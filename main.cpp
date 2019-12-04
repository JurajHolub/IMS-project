/**
 * @project VUT FIT - IMS project
 * @brief Simulation of production energy from solar panels for water heating.
 * Impact of energy production on environment and financial summarization of
 * solar panel construcitons verzus fosil (black coil) heating.
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include <iostream>
#include <simlib.h>
#include "monthly_process.h"
#include "statistics.h"
#include "argument_parser.h"

int main(int argc, char **argv)
{
	ArgumentParser argParser;
	if (!argParser.parseArgs(argc, argv))
	{
		argParser.printHelp();
		return 1;
	}

	printf("%-25s %-5d [years]\n", "Simulation time:", argParser.numberOfYears);
	printf("%-25s %-5d [l]\n", "Tank capacity:", argParser.tankCapacity);
	printf("%-25s %-5d [m2]\n", "Collector area:", argParser.collectorArea);
	printf("%-25s %-5d [degrees]\n", "Degree of roof:", argParser.roofDegree);

	RandomSeed(time(NULL));

	YearCycle *yearCycle = new YearCycle(1);

	// calculate required heat for warming WATER TANK
	double tankCapacity = argParser.tankCapacity * 10e-3;
	const double INPUT_WATER_TEMPERATURE = 0.1; // 10 degrees
	const double OUTPUT_WATER_TEMPERATURE = 0.5; // 50 degrees
	const double WATER_HEAT_CAPACITY = 41.8;
	const double WATER_DENSITY = 9.956;
	double requiredHeat; //required heat in kWh
	requiredHeat = WATER_HEAT_CAPACITY * WATER_DENSITY * tankCapacity * ( OUTPUT_WATER_TEMPERATURE - INPUT_WATER_TEMPERATURE ) * 1.1 / 36;

	double throughput = Uniform(0.85, 0.95);

	unsigned numberOfDaysPerYear = 365;
	unsigned numberOfDays = argParser.numberOfYears * numberOfDaysPerYear;

	Statistics *statistics = new Statistics();

	Init(0, numberOfDays - 1);
	MonthlyProcess *monthlyProcess = new MonthlyProcess(
		yearCycle,
		statistics,
		throughput,
		argParser.collectorArea,
		requiredHeat,
		(angle)argParser.roofDegree
	);
	monthlyProcess->Activate();

	Run();

	statistics->Output();

	delete yearCycle;
	delete statistics;
	delete monthlyProcess;

	return 0;
}

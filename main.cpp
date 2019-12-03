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
#include "monthly_energy_flow.h"
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
	// calculate only once
	double COLLECTOR_AREA = argParser.collectorArea;
	double TANK_CAPACITY = argParser.tankCapacity * 10e-3;
	double INPUT_WATER_TEMPERATURE = 0.1;
	double OUTPUT_WATER_TEMPERATURE = 0.5;
	double requiredHeat = 41.8 * 9.956 * TANK_CAPACITY * ( OUTPUT_WATER_TEMPERATURE - INPUT_WATER_TEMPERATURE ) * 1.1 / 0.036;
	angle degree = (angle)argParser.roofDegree;
	double throughput = Uniform(0.85, 0.95);

	unsigned numberOfDaysPerYear = 365;
	unsigned numberOfDays = argParser.numberOfYears * numberOfDaysPerYear;
	Init(0, numberOfDays - 1);
	MonthlyEnergyFlow *monthlyEnergyFlow = new MonthlyEnergyFlow(
		yearCycle,
		throughput,
		COLLECTOR_AREA,
		degree
	);
	monthlyEnergyFlow->Activate();

	Run();
	std::cout << "Spotreba: " << yearCycle->spotreba << "\n";
	std::cout << "Prebytok: " << yearCycle->prebytok << "\n";
	std::cout << "Nedostatok: " << yearCycle->nedostatok << "\n";
return 0;
/*
	Statistics *statistics = new Statistics(
			yearCycle,
			argParser.getConsumptionOfkWhPerDay(),
			argParser.getNumberOfProcessesPerkWh()
	);
	Store *dailyEnergyConsumption =new Store(
			"Daily usage of energy for water heating.",
			argParser.getConsumptionOfkWhPerDay()
	);
	statistics->Output();

	delete yearCycle;
	delete dailyEnergyConsumption;
	delete statistics;
	delete monthlyEnergyFlow;

	return 0;
 */
}

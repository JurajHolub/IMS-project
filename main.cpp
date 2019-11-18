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

	RandomSeed(time(NULL));
	YearCycle *yearCycle = new YearCycle(argParser.getNumberOfProcessesPerkWh());
	Statistics *statistics = new Statistics(
			yearCycle,
			argParser.getConsumptionOfkWhPerDay(),
			argParser.getNumberOfProcessesPerkWh()
	);
	Store *dailyEnergyConsumption =new Store(
			"Daily usage of energy for water heating.",
			argParser.getConsumptionOfkWhPerDay()
	);

	unsigned numberOfDaysPerYear = 365;
	unsigned numberOfDays = argParser.getNumberOfYears() * numberOfDaysPerYear;
	Init(0, numberOfDays - 1);
	MonthlyEnergyFlow *monthlyEnergyFlow = new MonthlyEnergyFlow(yearCycle, dailyEnergyConsumption, statistics);
	monthlyEnergyFlow->Activate();

	Run();
	statistics->Output();

	delete yearCycle;
	delete dailyEnergyConsumption;
	delete statistics;
	delete monthlyEnergyFlow;

	return 0;
}

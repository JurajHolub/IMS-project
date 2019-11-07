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

#define MONTH_ENERGY_CONSUMPTION 3090

int main(int argc, char **argv)
{
	ArgumentParser argumentParser;
	if (!argumentParser.parseArgs(argc, argv))
	{
		argumentParser.printHelp();
		return 1;
	}

	Facility *monthCycle = new Facility("New month cycle facility");
	YearCycle *yearCycle = new YearCycle();
	Statistics *statistics = new Statistics(yearCycle, argumentParser.getConsumptionOfkWhPerMonth());
	Store *monthlyEnergyConsumption =new Store(
		"Monthly usage of energy for water heating",
		argumentParser.getConsumptionOfkWhPerMonth()
	);

	unsigned numberOfDays = argumentParser.getNumberOfYears() * 365 - 1;
	Init(0, numberOfDays);
	MonthlyEnergyFlow *monthlyEnergyFlow = new MonthlyEnergyFlow(yearCycle, monthCycle, monthlyEnergyConsumption, statistics);
	monthlyEnergyFlow->Activate();

	Run();
	statistics->Output();

	delete yearCycle;
	delete monthCycle;
	delete monthlyEnergyConsumption;
	delete statistics;
	delete monthlyEnergyFlow;

	return 0;
}

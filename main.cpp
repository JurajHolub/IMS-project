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

#define MONTH_ENERGY_CONSUMPTION 3090

int main(int argc, char **argv)
{
	Facility *monthCycle = new Facility("New month cycle facility");
	YearCycle *yearCycle = new YearCycle();
	Statistics *statistics = new Statistics(yearCycle);
	Store *monthlyEnergyConsumption = new Store("Monthly usage of energy for water heating", MONTH_ENERGY_CONSUMPTION);

	Init(0, 364);
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

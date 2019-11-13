/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include <iostream>
#include "monthly_energy_flow.h"
#include "solar_energy_source.h"

MonthlyEnergyFlow::MonthlyEnergyFlow(
	YearCycle *yearCycle,
	Store *dailyEnergyConsumption,
	Statistics *statistics)
{
	this->yearCycle = yearCycle;
	this->dailyEnergyConsumption = dailyEnergyConsumption;
	this->statistics = statistics;
}

void MonthlyEnergyFlow::Behavior()
{
	while (1)
	{
		yearCycle->setNewMonth();
		for (int i = 0; i < yearCycle->getCurrentSolarEnergyProduction(); ++i)
		{
			auto source = new SolarEnergySource(yearCycle, this, dailyEnergyConsumption, statistics);
			double t = Time + Uniform(0, yearCycle->getNumberOfDaysForCurrentMonth() - 1);
			source->Activate(t);
		}
		Wait(yearCycle->getNumberOfDaysForCurrentMonth());
	}
}

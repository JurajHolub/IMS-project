/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "monthly_energy_flow.h"
#include "solar_energy_source.h"

MonthlyEnergyFlow::MonthlyEnergyFlow(
	YearCycle *yearCycle,
	Facility *monthCycle,
	Store *monthlyEnergyConsumption,
	Statistics *statistics)
{
	this->yearCycle = yearCycle;
	this->monthCycle = monthCycle;
	this->monthlyEnergyConsumption = monthlyEnergyConsumption;
	this->statistics = statistics;
}

void MonthlyEnergyFlow::setEndOfMonthCycle()
{
	Release(*monthCycle);
}

void MonthlyEnergyFlow::Behavior()
{
	while (1)
	{
		Seize(*monthCycle);
		yearCycle->setNewMonth();
		for (int i = 0; i < yearCycle->getCurrentSolarEnergyProduction(); ++i)
		{
			auto source = new SolarEnergySource(yearCycle, this, monthlyEnergyConsumption, statistics);
			double t = Time + Uniform(0, yearCycle->getNumberOfDaysForCurrentMonth());
			source->Activate(t);
		}
		Wait(yearCycle->getNumberOfDaysForCurrentMonth());
	}
}

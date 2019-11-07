/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "solar_energy_source.h"

SolarEnergySource::SolarEnergySource
(
	YearCycle *yearCycle,
	MonthlyEnergyFlow *monthlyEnergyFlow,
	Store *monthlyEnergyConsumption,
	Statistics *statistics
)
{
	this->yearCycle = yearCycle;
	this->monthlyEnergyFlow = monthlyEnergyFlow;
	this->monthlyEnergyConsumption = monthlyEnergyConsumption;
	this->statistics = statistics;
}

void SolarEnergySource::Behavior()
{
	statistics->consumeEnergy();

	if (monthlyEnergyConsumption->Full())
	{
		statistics->wasteSolarEnergy();
	}
	else
	{
		Enter(*monthlyEnergyConsumption, 1);
		statistics->consumeSolarEnergy();
	}

	if (statistics->monthlyEnergyNeedFulfilled())
	{
		while (!monthlyEnergyConsumption->Empty())
			Leave(*monthlyEnergyConsumption, 1);

		monthlyEnergyFlow->setEndOfMonthCycle();
	}
}

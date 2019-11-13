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
	Store *dailyEnergyConsumption,
	Statistics *statistics
)
{
	this->yearCycle = yearCycle;
	this->monthlyEnergyFlow = monthlyEnergyFlow;
	this->dailyEnergyConsumption = dailyEnergyConsumption;
	this->statistics = statistics;
}

void SolarEnergySource::Behavior()
{
	statistics->consumeEnergy();

	if (dailyEnergyConsumption->Full())
	{
		statistics->wasteSolarEnergy();
	}
	else
	{
		Enter(*dailyEnergyConsumption, 1);
		statistics->consumeSolarEnergy();
		Wait(1); // wait one day to release daily consumption
		Leave(*dailyEnergyConsumption, 1);
	}
}

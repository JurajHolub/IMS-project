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
	double dailyEnergyProduct
)
{
	this->yearCycle = yearCycle;
	this->dailyEnergyProduct = dailyEnergyProduct;
}

void SolarEnergySource::Behavior()
{
	double TANK_CAPACITY = 200 * 10e-3;
	double INPUT_WATER_TEMPERATURE = 0.1;
	double OUTPUT_WATER_TEMPERATURE = 0.5;
	double requiredHeat = 41.8 * 9.956 * TANK_CAPACITY * ( OUTPUT_WATER_TEMPERATURE - INPUT_WATER_TEMPERATURE ) * 1.1 / 36;
	double dailyEnergyConsumption = Exponential(requiredHeat);
	double bilance = dailyEnergyProduct - dailyEnergyConsumption;

	if (dailyEnergyProduct < dailyEnergyConsumption)
	{
		// nedostatok
		yearCycle->nedostatok += dailyEnergyConsumption - dailyEnergyProduct;
	}
	else
	{
		// prebytok
		yearCycle->prebytok += dailyEnergyProduct - dailyEnergyConsumption;
	}
	yearCycle->spotreba += dailyEnergyConsumption;
}

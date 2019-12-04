/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "daily_process.h"

DayilyProcess::DayilyProcess
(
	YearCycle *yearCycle,
	Statistics *stat,
	double dailyEnergyProduct,
	double requiredHeat
)
{
	this->yearCycle = yearCycle;
	this->stat = stat;
	this->dailyEnergyProduct = dailyEnergyProduct;
	this->requiredHeat = requiredHeat;
}

void DayilyProcess::Behavior()
{
	double dailyEnergyConsumption = Exponential(requiredHeat);

	stat->consumedEnergy += dailyEnergyConsumption;
	if (dailyEnergyProduct < dailyEnergyConsumption)
	{
		stat->consumedSolarEnergy += dailyEnergyProduct;
		stat->consumedFosilEnergy += dailyEnergyConsumption - dailyEnergyProduct;
	}
	else
	{
		stat->consumedSolarEnergy += dailyEnergyConsumption;
		stat->energyWaste += dailyEnergyProduct - dailyEnergyConsumption;
	}
}

/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "statistics.h"
#include <iostream>

Statistics::Statistics(YearCycle *yearCycle, unsigned monthConsumption)
{
	this->yearCycle = yearCycle;
	this->monthConsumption = monthConsumption;
	consumedSolarEnergy = 0;
	consumedFosilEnergy = 0;
	energyWaste = 0;
	monthlySpent = 0;
}

unsigned Statistics::calculateFosilEnergy()
{
	unsigned yearConsumption = monthConsumption * 12;
	return yearConsumption * yearCycle->getNumberOfYears() - consumedSolarEnergy;
}

void Statistics::consumeSolarEnergy()
{
	consumedSolarEnergy++;
}

void Statistics::consumeEnergy()
{
	monthlySpent++;
}

bool Statistics::monthlyEnergyNeedFulfilled()
{
	if (monthlySpent == yearCycle->getCurrentSolarEnergyProduction())
	{
		monthlySpent = 0;
		return true;
	}

	return false;
}

void Statistics::wasteSolarEnergy()
{
	energyWaste++;
}

void Statistics::Output()
{
	unsigned consumedEnergyTotal = consumedSolarEnergy + calculateFosilEnergy();
	double priceWithSystem = COST_OF_SOLAR_PANEL_SET + calculateFosilEnergy() * COST_OF_BLACK_COAL_ENERGY_PER_KWH;
	double priceWithoutSystem = consumedEnergyTotal * COST_OF_BLACK_COAL_ENERGY_PER_KWH;
	double emisionsWithSystem = (consumedSolarEnergy + energyWaste) * GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_SOLAR_ENERGY;
	double emisionsWithoutSystem = consumedEnergyTotal * GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_COAL_ENERGY;

	printf("Consumed solar energy:             %10d [kWh]\n", consumedSolarEnergy);
	printf("Consumed fosil energy:             %10d [kWh]\n", calculateFosilEnergy());
	printf("Wasted solar energy:               %10d [kWh]\n", energyWaste);
	printf("Consumed total:                    %10d [kWh]\n", consumedEnergyTotal);
	printf("Price without solar system:        %10.2f [CZK]\n", priceWithoutSystem);
	printf("Price with solar system:           %10.2f [CZK]\n", priceWithSystem);
	printf("CO2 emisions with solar system:    %10.2f [g]\n",  emisionsWithSystem);
	printf("CO2 emisions without solar system: %10.2f [g]\n",  emisionsWithoutSystem);
}
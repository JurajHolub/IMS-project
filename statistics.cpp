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
	unsigned priceWithSystem = 82000 +calculateFosilEnergy() * 1.29;
	unsigned priceWithoutSystem = consumedEnergyTotal * 1.29;
	unsigned emisionsWithSystem = (consumedSolarEnergy + energyWaste) * 0.000024 * 1000;
	unsigned emisionsWithoutSystem = consumedEnergyTotal * 0.001041 * 1000;

	printf("Consumed solar energy:             %10d [kWh]\n", consumedSolarEnergy);
	printf("Consumed fosil energy:             %10d [kWh]\n", calculateFosilEnergy());
	printf("Wasted solar energy:               %10d [kWh]\n", energyWaste);
	printf("Consumed total:                    %10d [kWh]\n", consumedEnergyTotal);
	printf("Price without solar system:        %10d [CZK]\n", priceWithoutSystem);
	printf("Price with solar system:           %10d [CZK]\n", priceWithSystem);
	printf("CO2 emisions with solar system:    %10d [kg]\n",  emisionsWithSystem);
	printf("CO2 emisions without solar system: %10d [kg]\n",  emisionsWithoutSystem);
}
/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "statistics.h"
#include <iostream>

Statistics::Statistics(YearCycle *yearCycle)
{
	this->yearCycle = yearCycle;
	consumedSolarEnergy = 0;
	consumedFosilEnergy = 0;
	energyWaste = 0;
	monthlySpent = 0;
}

void Statistics::consumeFosilEnergy()
{
	consumedFosilEnergy++;
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
	std::cout << "Consumed fosil energy: " << consumedFosilEnergy << "\n";
	std::cout << "Consumed solar energy: " << consumedSolarEnergy*.1 << "\n";
	std::cout << "Wasted solar energy  : " << energyWaste*.1 << "\n";
	std::cout << "Consumed total       : " << (consumedSolarEnergy*.1 + consumedFosilEnergy) << "\n";
	std::cout << "Price without solar system: " << (consumedSolarEnergy + consumedFosilEnergy) * .1 * 1.29 << "\n";
	std::cout << "Price with solar system   : " << 82000 + consumedFosilEnergy * .1 * 1.29 << "\n";
	std::cout << "Production of CO2 without solar system: " << (consumedSolarEnergy + consumedFosilEnergy) * .1 * .001041 << "\n";
	std::cout << "Production of CO2 with solar system                          : " << consumedFosilEnergy * .1 * .001041 + (energyWaste + consumedSolarEnergy) * .1 * .000024 << "\n";
	std::cout << "Production of CO2 with solar system(energy waste included)   : " << consumedFosilEnergy * .1 * .001041 + (consumedSolarEnergy) * .1 * .000024 << "\n";
}
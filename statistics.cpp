/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "statistics.h"
#include <iostream>

Statistics::Statistics(YearCycle *yearCycle, unsigned dailyConsumption, unsigned numberOfprocessesPerDay)
{
	this->yearCycle = yearCycle;
	this->dailyConsumption = dailyConsumption;
	this->numberOfProcessesPerDay = numberOfprocessesPerDay;
	consumedSolarEnergy = 0;
	consumedFosilEnergy = 0;
	consumedEnergy = 0;
	energyWaste = 0;
}

unsigned Statistics::calculateFosilEnergy()
{
	unsigned numberOfDaysInOneYear = 365;
	unsigned yearConsumption = dailyConsumption * numberOfDaysInOneYear / numberOfProcessesPerDay;
	return yearConsumption * yearCycle->getNumberOfYears() - consumedSolarEnergy;
}

void Statistics::consumeSolarEnergy()
{
	consumedSolarEnergy++;
}


void Statistics::wasteSolarEnergy()
{
	energyWaste++;
}

void Statistics::divideStatisticsByNumberOfProcesses()
{
	consumedSolarEnergy /= numberOfProcessesPerDay;
	energyWaste /= numberOfProcessesPerDay;
}

void Statistics::consumeEnergy()
{
}

void Statistics::Output()
{
	divideStatisticsByNumberOfProcesses();

	unsigned fosilEnergy = calculateFosilEnergy();
	unsigned consumedEnergyTotal = (consumedSolarEnergy + fosilEnergy);
	double priceWithSystem = COST_OF_SOLAR_PANEL_SET + fosilEnergy * COST_OF_BLACK_COAL_ENERGY_PER_KWH;
	double priceWithoutSystem = consumedEnergyTotal * COST_OF_BLACK_COAL_ENERGY_PER_KWH;
	double emisionsWithSystem = (consumedSolarEnergy + energyWaste) * GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_SOLAR_ENERGY;
	double emisionsWithoutSystem = consumedEnergyTotal * GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_COAL_ENERGY;


	printf("Consumed solar energy:             %10d [kWh]\n", consumedSolarEnergy);
	printf("Consumed fosil energy:             %10d [kWh]\n", fosilEnergy);
	printf("Wasted solar energy:               %10d [kWh]\n", energyWaste);
	printf("Consumed total:                    %10d [kWh]\n", consumedEnergyTotal);
	printf("Price without solar system:        %10.2f [CZK]\n", priceWithoutSystem);
	printf("Price with solar system:           %10.2f [CZK]\n", priceWithSystem);
	printf("CO2 emisions with solar system:    %10.2f [g]\n",  emisionsWithSystem);
	printf("CO2 emisions without solar system: %10.2f [g]\n",  emisionsWithoutSystem);
}
/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "statistics.h"
#include <iostream>

void Statistics::Output()
{
	//double priceWithSystem = COST_OF_SOLAR_PANEL_SET + consumedFosilEnergy * COST_OF_NATURAL_GAS_ENERGY_PER_KWH;
	//double priceWithoutSystem = consumedEnergy * COST_OF_NATURAL_GAS_ENERGY_PER_KWH;
	double emisionsWithSystem = consumedFosilEnergy * GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_NATURAL_GAS * 10e-3;
	double emisionsWithoutSystem = consumedEnergy * GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_NATURAL_GAS * 10e-3;


	printf("=================== STATISTICS ===================\n");
	printf("Consumed solar energy:             %.2f [kWh]\n", consumedSolarEnergy);
	printf("Consumed fosil energy:             %.2f [kWh]\n", consumedFosilEnergy);
	printf("Wasted solar energy:               %.2f [kWh]\n", energyWaste);
	printf("Consumed total:                    %.2f [kWh]\n", consumedEnergy);
	//printf("Price without solar system:        %.2f [CZK]\n", priceWithoutSystem);
	//printf("Price with solar system:           %.2f [CZK]\n", priceWithSystem);
	printf("CO2 emisions with solar system:    %.2f [kg]\n",  emisionsWithSystem);
	printf("CO2 emisions without solar system: %.2f [kg]\n",  emisionsWithoutSystem);
}
/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_STATISTICS_H
#define IMS_PROJECT_STATISTICS_H

#include "year_cycle.h"

class Statistics {
public:
	double consumedSolarEnergy;
	double consumedFosilEnergy;
	double consumedEnergy;
	double energyWaste;

	const double COST_OF_NATURAL_GAS_ENERGY_PER_KWH = 1.71; //CZK
	const double COST_OF_SOLAR_PANEL_SET = 82000; //CZK
	const double GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_NATURAL_GAS = 202;

public:

	void Output();
};


#endif //IMS_PROJECT_STATISTICS_H

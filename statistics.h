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
private:
	YearCycle * yearCycle;
	unsigned dailyConsumption;
	unsigned consumedSolarEnergy;
	unsigned consumedFosilEnergy;
	unsigned consumedEnergy;
	unsigned energyWaste;
	unsigned numberOfProcessesPerDay;

	const double COST_OF_BLACK_COAL_ENERGY_PER_KWH = 1.29;
	const double COST_OF_SOLAR_PANEL_SET = 71769;
	const double GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_COAL_ENERGY = 1.041e-3;
	const double GRAMMS_OF_CO2_PRODUCTION_PER_KWH_OF_SOLAR_ENERGY = 2.4e-5;

public:

	Statistics(YearCycle *yearCycle, unsigned dailyConsumption, unsigned numberOfprocessesPerDay);

	void consumeSolarEnergy();
	unsigned calculateFosilEnergy();
	void consumeEnergy();
	void wasteSolarEnergy();
	void divideStatisticsByNumberOfProcesses();

	void Output();
};


#endif //IMS_PROJECT_STATISTICS_H

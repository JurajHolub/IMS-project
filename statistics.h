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
	unsigned monthConsumption;
	unsigned consumedSolarEnergy;
	unsigned consumedFosilEnergy;
	unsigned energyWaste;
	unsigned monthlySpent;
public:

	Statistics(YearCycle *yearCycle, unsigned yearConsumption);

	void consumeSolarEnergy();
	unsigned calculateFosilEnergy();
	void consumeEnergy();
	void wasteSolarEnergy();
	bool monthlyEnergyNeedFulfilled();

	void Output();
};


#endif //IMS_PROJECT_STATISTICS_H

/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_SOLAR_ENERGY_SOURCE_H
#define IMS_PROJECT_SOLAR_ENERGY_SOURCE_H

#include <simlib.h>
#include "year_cycle.h"
#include "monthly_energy_flow.h"
#include "statistics.h"

class SolarEnergySource : public Process {
private:
	YearCycle *yearCycle;
	MonthlyEnergyFlow *monthlyEnergyFlow;
	Store *monthlyEnergyConsumption;
	Statistics * statistics;
public:
	SolarEnergySource(
		YearCycle *yearCycle,
		MonthlyEnergyFlow *monthlyEnergyFlow,
		Store *monthlyEnergyConsumption,
		Statistics * statistics);

	void Behavior() override ;

};


#endif //IMS_PROJECT_SOLAR_ENERGY_SOURCE_H

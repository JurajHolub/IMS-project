/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_MONTHLY_ENERGY_FLOW_H
#define IMS_PROJECT_MONTHLY_ENERGY_FLOW_H

#include <simlib.h>
#include <map>
#include "year_cycle.h"
#include "statistics.h"

class MonthlyEnergyFlow : public Process {
private:
	YearCycle *yearCycle;
	double throughput;
	unsigned collectorArea;
	angle degree;

public:

	MonthlyEnergyFlow(
		YearCycle *yearCycle,
		double throughput,
		unsigned collectorArea,
		angle degree
	);

	void setEndOfMonthCycle();
	void Behavior() override ;

};


#endif //IMS_PROJECT_MONTHLY_ENERGY_FLOW_H

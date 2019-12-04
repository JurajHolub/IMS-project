/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_MONTHLY_PROCESS_H
#define IMS_PROJECT_MONTHLY_PROCESS_H

#include <simlib.h>
#include <map>
#include "year_cycle.h"
#include "statistics.h"

class MonthlyProcess : public Process {
private:
	YearCycle *yearCycle;
	Statistics *stat;
	double throughput;
	unsigned collectorArea;
	double requiredHeat;
	angle degree;

public:

	MonthlyProcess(
		YearCycle *yearCycle,
		Statistics *stat,
		double throughput,
		unsigned collectorArea,
		double requiredHeat,
		angle degree
	);

	void Behavior() override ;

};


#endif //IMS_PROJECT_MONTHLY_PROCESS_H

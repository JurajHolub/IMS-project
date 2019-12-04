/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_DAILY_PROCESS_H
#define IMS_PROJECT_DAILY_PROCESS_H

#include <simlib.h>
#include "year_cycle.h"
#include "monthly_process.h"
#include "statistics.h"

class DayilyProcess : public Process {
private:
	YearCycle *yearCycle;
	Statistics *stat;
	double dailyEnergyProduct;
	double requiredHeat;
public:
	DayilyProcess(
		YearCycle *yearCycle,
		Statistics *stat,
		double dailyEnergyProduct,
		double requiredHeat
	);

	void Behavior() override ;

};


#endif //IMS_PROJECT_DAILY_PROCESS_H

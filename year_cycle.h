/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_YEAR_CYCLE_H
#define IMS_PROJECT_YEAR_CYCLE_H

#include <map>

class YearCycle {

private:

	enum Months {
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		Septembre,
		Octobre,
		Novembre,
		Decembre
	};

	std::map<Months, unsigned > numberOfMonthDay {
			{January, 31},
			{February, 28},
			{March,  31},
			{April,  30},
			{May,    31},
			{June,   30},
			{July,   31},
			{August, 31},
			{Septembre, 30},
			{Octobre, 31},
			{Novembre, 30},
			{Decembre, 31}
	};

	std::map<Months, unsigned > monthlySolarProduction {
			{January, 372},
			{February, 1124},
			{March,  2699},
			{April,  3707},
			{May,    6178},
			{June,   7176},
			{July,   7689},
			{August, 6012},
			{Septembre, 4181},
			{Octobre, 1914},
			{Novembre, 583},
			{Decembre, 166}
	};

	Months currentMonth;
	unsigned year;

public:

	YearCycle();

	Months getCurrentMonth();
	Months setNewMonth();
	unsigned getNumberOfDaysForCurrentMonth();
	unsigned getCurrentSolarEnergyProduction();
};


#endif //IMS_PROJECT_YEAR_CYCLE_H

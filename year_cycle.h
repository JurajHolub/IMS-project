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
			{January, 	31},
			{February, 	28},
			{March,  	31},
			{April,  	30},
			{May,    	31},
			{June,   	30},
			{July,   	31},
			{August, 	31},
			{Septembre, 	30},
			{Octobre, 	31},
			{Novembre, 	30},
			{Decembre, 	31}
	};

	std::map<Months, unsigned > monthlySolarProduction {
			{January, 	37},
			{February, 	112},
			{March,  	269},
			{April,  	370},
			{May,    	617},
			{June,   	717},
			{July,   	768},
			{August, 	601},
			{Septembre, 	418},
			{Octobre, 	191},
			{Novembre, 	58},
			{Decembre, 	16}
	};

	Months currentMonth;
	unsigned year;

public:

	YearCycle();

	Months getCurrentMonth();
	Months setNewMonth();
	unsigned getNumberOfDaysForCurrentMonth();
	unsigned getCurrentSolarEnergyProduction();
	unsigned getNumberOfYears();
};


#endif //IMS_PROJECT_YEAR_CYCLE_H

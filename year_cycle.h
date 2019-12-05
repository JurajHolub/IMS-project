/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_YEAR_CYCLE_H
#define IMS_PROJECT_YEAR_CYCLE_H

#include <map>

enum Angle {
	_0_DEGREE  = 0,
	_15_DEGREE = 15,
	_30_DEGREE = 30,
	_45_DEGREE = 45,
	_60_DEGREE = 60,
	_75_DEGREE = 75,
	_90_DEGREE = 90
};

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

class YearCycle {

public:

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

	Months currentMonth;
	unsigned year;


public:

	YearCycle();

	Months getCurrentMonth();
	Months setNewMonth();
	unsigned getNumberOfDaysForCurrentMonth();
	unsigned getNumberOfYears();
};


#endif //IMS_PROJECT_YEAR_CYCLE_H

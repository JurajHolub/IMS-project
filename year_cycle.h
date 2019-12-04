/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#ifndef IMS_PROJECT_YEAR_CYCLE_H
#define IMS_PROJECT_YEAR_CYCLE_H

#include <map>

enum angle {
	_0_DEGREE  = 0,
	_15_DEGREE = 15,
	_30_DEGREE = 30,
	_45_DEGREE = 45,
	_60_DEGREE = 60,
	_75_DEGREE = 75,
	_90_DEGREE = 90
};

class YearCycle {

public:

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

	std::map<Months, double> MEAN_TEMPERATURE_OF_SUNLIGHT_BRNO {
		{January, 	1.7},
		{February, 	2.8},
		{March,  	7.0},
		{April,  	12.0},
		{May,    	17.2},
		{June,   	20.2},
		{July,   	22.1},
		{August, 	21.8},
		{Septembre, 18.5},
		{Octobre, 	13.1},
		{Novembre, 	7.7},
		{Decembre, 	3.5}
	};

	std::map<angle, std::map<Months, unsigned>> MEAN_INTENSITY_OF_SUNLIGHT_BRNO {
		{ _0_DEGREE,
			{
				{January, 	188},
				{February, 	271},
				{March,  	411},
				{April,  	484},
				{May,    	534},
				{June,   	561},
				{July,   	534},
				{August, 	484},
				{Septembre,  411},
				{Octobre, 	271},
				{Novembre, 	188},
				{Decembre, 	139}
			}
		},
		{ _30_DEGREE,
			{
				{January, 	358},
				{February, 	443},
				{March,  	537},
				{April,  	574},
				{May,    	609},
				{June,   	611},
				{July,   	609},
				{August, 	574},
				{Septembre, 537},
				{Octobre, 	443},
				{Novembre, 	358},
				{Decembre, 	299}
			}
		},
	};

	std::map<angle, std::map<Months, double>> TEORETICAL_CAPTURED_SUNLIGHT_BRNO {
		{ _0_DEGREE,
			{
				{January, 	1.55},
				{February, 	2.74},
				{March,  	4.93},
				{April,  	6.73},
				{May,    	8.34},
				{June,   	9.16},
				{July,   	8.34},
				{August, 	6.73},
				{Septembre,	4.93},
				{Octobre, 	2.74},
				{Novembre, 	1.55},
				{Decembre, 	1.09}
			}
		},
		{ _30_DEGREE,
			{
				{January, 	2.96},
				{February, 	4.48},
				{March,  	6.44},
				{April,  	7.98},
				{May,    	9.56},
				{June,   	9.98},
				{July,   	9.56},
				{August, 	7.98},
				{Septembre,	6.44},
				{Octobre, 	4.48},
				{Novembre, 	2.96},
				{Decembre, 	2.35}
			}
		},
	};

	std::map<Months, double> SUNLIGHT_RATIO_BRNO {
			{January, 	0.18},
			{February, 	0.31},
			{March,  	0.38},
			{April,  	0.39},
			{May,    	0.48},
			{June,   	0.53},
			{July,   	0.56},
			{August, 	0.53},
			{Septembre,	0.50},
			{Octobre, 	0.37},
			{Novembre, 	0.23},
			{Decembre, 	0.12}
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
	unsigned numberOfProcessesPerDay;


public:

	YearCycle(unsigned numberOfProcessesPerDay);

	Months getCurrentMonth();
	Months setNewMonth();
	unsigned getNumberOfDaysForCurrentMonth();
	unsigned getCurrentSolarEnergyProduction();
	unsigned getNumberOfYears();
};


#endif //IMS_PROJECT_YEAR_CYCLE_H

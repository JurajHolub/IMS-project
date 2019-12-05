//
// Created by juraj on 05/12/2019.
//

#include "sunlight_brno.h"

std::map<Months, double> SunlightBrno::MEAN_TEMPERATURE_OF_SUNLIGHT_BRNO = {
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

std::map<Months, double> SunlightBrno::SUNLIGHT_RATIO_BRNO {
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

double SunlightBrno::getMeanTemperate(Months month)
{
	return MEAN_TEMPERATURE_OF_SUNLIGHT_BRNO[month];
}

double SunlightBrno::getRatio(Months month)
{
	return SUNLIGHT_RATIO_BRNO[month];
}

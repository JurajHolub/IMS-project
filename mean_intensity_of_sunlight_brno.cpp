//
// Created by juraj on 05/12/2019.
//

#include "mean_intensity_of_sunlight_brno.h"

std::map<Angle, std::map<Months , unsigned >> MeanIntensityOfSunlightBrno::MEAN_INTENSITY_OF_SUNLIGHT_BRNO = {
		{ Angle ::_0_DEGREE,
				{
						{Months::January, 	188},
						{Months::February, 	271},
						{Months::March,  	411},
						{Months::April,  	484},
						{Months::May,    	534},
						{Months::June,   	561},
						{Months::July,   	534},
						{Months::August, 	484},
						{Months::Septembre,  411},
						{Months::Octobre, 	271},
						{Months::Novembre, 	188},
						{Months::Decembre, 	139}
				}
		},
		{ Angle ::_15_DEGREE,
				{
						{Months::January, 	278},
						{Months::February, 	371},
						{Months::March,  	485},
						{Months::April,  	540},
						{Months::May,    	581},
						{Months::June,   	597},
						{Months::July,   	581},
						{Months::August, 	540},
						{Months::Septembre,  485},
						{Months::Octobre, 	371},
						{Months::Novembre, 	278},
						{Months::Decembre, 	227}
				}
		},
		{ Angle ::_30_DEGREE,
				{
						{Months::January, 	358},
						{Months::February, 	443},
						{Months::March,  	537},
						{Months::April,  	574},
						{Months::May,    	609},
						{Months::June,   	611},
						{Months::July,   	609},
						{Months::August, 	574},
						{Months::Septembre, 537},
						{Months::Octobre, 	443},
						{Months::Novembre, 	358},
						{Months::Decembre, 	299}
				}
		},
		{ Angle ::_45_DEGREE,
				{
						{Months::January, 	412},
						{Months::February, 	490},
						{Months::March,  	558},
						{Months::April,  	580},
						{Months::May,    	600},
						{Months::June,   	590},
						{Months::July,   	600},
						{Months::August, 	580},
						{Months::Septembre, 558},
						{Months::Octobre, 	490},
						{Months::Novembre, 	412},
						{Months::Decembre, 	344}
				}
		},
		{ Angle ::_60_DEGREE,
				{
						{Months::January, 	449},
						{Months::February, 	520},
						{Months::March,  	545},
						{Months::April,  	533},
						{Months::May,    	515},
						{Months::June,   	519},
						{Months::July,   	515},
						{Months::August, 	533},
						{Months::Septembre, 545},
						{Months::Octobre, 	520},
						{Months::Novembre, 	449},
						{Months::Decembre, 	382}
				}
		},
		{ Angle ::_75_DEGREE,
				{
						{Months::January, 	472},
						{Months::February, 	526},
						{Months::March,  	520},
						{Months::April,  	463},
						{Months::May,    	410},
						{Months::June,   	394},
						{Months::July,   	410},
						{Months::August, 	463},
						{Months::Septembre, 520},
						{Months::Octobre, 	526},
						{Months::Novembre, 	472},
						{Months::Decembre, 	392}
				}
		},
		{ Angle ::_90_DEGREE,
				{
						{Months::January, 	479},
						{Months::February, 	494},
						{Months::March,  	463},
						{Months::April,  	373},
						{Months::May,    	286},
						{Months::June,   	264},
						{Months::July,   	286},
						{Months::August, 	373},
						{Months::Septembre, 463},
						{Months::Octobre, 	494},
						{Months::Novembre, 	479},
						{Months::Decembre, 	396}
				}
		},
};

unsigned MeanIntensityOfSunlightBrno::get(Months month, Angle angle)
{
	return MEAN_INTENSITY_OF_SUNLIGHT_BRNO[angle][month];
}

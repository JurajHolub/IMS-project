//
// Created by juraj on 05/12/2019.
//

#include "teoretical_incident_sunlight_brno.h"

std::map<Angle, std::map<Months, double>> TeoreticalIncidentSunlightBrno::TEORETICAL_INCIDENT_SUNLIGHT_BRNO  = {
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
		{ _15_DEGREE,
		  {
				  {January, 	2.30},
				  {February, 	3.75},
				  {March,  	5.82},
				  {April,  	7.50},
				  {May,    	9.12},
				  {June,   	9.76},
				  {July,   	9.12},
				  {August, 	7.50},
				  {Septembre,	5.82},
				  {Octobre, 	3.75},
				  {Novembre, 	2.30},
				  {Decembre, 	1.78}
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
		{ _45_DEGREE,
		  {
				  {January, 	3.40},
				  {February, 	4.96},
				  {March,  	6.70},
				  {April,  	8.06},
				  {May,    	9.42},
				  {June,   	9.64},
				  {July,   	9.42},
				  {August, 	8.06},
				  {Septembre,	6.70},
				  {Octobre, 	4.96},
				  {Novembre, 	3.40},
				  {Decembre, 	2.70}
		  }
		},
		{ _60_DEGREE,
		  {
				  {January, 	3.71},
				  {February, 	5.26},
				  {March,  	6.54},
				  {April,  	7.41},
				  {May,    	8.09},
				  {June,   	8.48},
				  {July,   	8.09},
				  {August, 	7.41},
				  {Septembre,	6.54},
				  {Octobre, 	5.26},
				  {Novembre, 	3.71},
				  {Decembre, 	3.00}
		  }
		},
		{ _75_DEGREE,
		  {
				  {January, 	3.90},
				  {February, 	5.32},
				  {March,  	6.24},
				  {April,  	6.44},
				  {May,    	6.44},
				  {June,   	6.44},
				  {July,   	6.44},
				  {August, 	6.44},
				  {Septembre,	6.44},
				  {Octobre, 	5.32},
				  {Novembre, 	3.90},
				  {Decembre, 	3.08}
		  }
		},
		{ _90_DEGREE,
		  {
				  {January, 	3.96},
				  {February, 	5.00},
				  {March,  	5.56},
				  {April,  	5.19},
				  {May,    	4.49},
				  {June,   	4.31},
				  {July,   	4.49},
				  {August, 	5.19},
				  {Septembre,	5.56},
				  {Octobre, 	5.00},
				  {Novembre, 	3.96},
				  {Decembre, 	3.11}
		  }
		},
};

double TeoreticalIncidentSunlightBrno::get(Months month, Angle angle)
{
	return TEORETICAL_INCIDENT_SUNLIGHT_BRNO[angle][month];
}

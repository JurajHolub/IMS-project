//
// Created by juraj on 05/12/2019.
//

#ifndef IMS_PROJECT_SUNLIGHT_BRNO_H
#define IMS_PROJECT_SUNLIGHT_BRNO_H

#include "year_cycle.h"
#include <map>

class SunlightBrno {

public:

 static double getMeanTemperate(Months month);
 static double getRatio(Months month);

private:

	static std::map<Months, double> MEAN_TEMPERATURE_OF_SUNLIGHT_BRNO;
	static std::map<Months, double> SUNLIGHT_RATIO_BRNO;

};


#endif //IMS_PROJECT_SUNLIGHT_BRNO_H

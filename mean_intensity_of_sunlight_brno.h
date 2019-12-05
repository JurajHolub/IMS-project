//
// Created by juraj on 05/12/2019.
//

#ifndef IMS_PROJECT_MEAN_INTENSITY_OF_SUNLIGHT_BRNO_H
#define IMS_PROJECT_MEAN_INTENSITY_OF_SUNLIGHT_BRNO_H

#include "year_cycle.h"
#include <map>

class MeanIntensityOfSunlightBrno {
public:
	static unsigned get(Months month, Angle agnle);

private:

	static std::map<Angle, std::map<Months , unsigned >> MEAN_INTENSITY_OF_SUNLIGHT_BRNO;

};


#endif //IMS_PROJECT_MEAN_INTENSITY_OF_SUNLIGHT_BRNO_H

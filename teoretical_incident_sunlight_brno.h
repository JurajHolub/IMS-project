//
// Created by juraj on 05/12/2019.
//

#ifndef IMS_PROJECT_TEORETICAL_INCIDENT_SUNLIGHT_BRNO_H
#define IMS_PROJECT_TEORETICAL_INCIDENT_SUNLIGHT_BRNO_H

#include <map>
#include "year_cycle.h"

class TeoreticalIncidentSunlightBrno {
public:
	static double get(Months month, Angle angle);

private:

	static std::map<Angle, std::map<Months, double>> TEORETICAL_INCIDENT_SUNLIGHT_BRNO;
};


#endif //IMS_PROJECT_TEORETICAL_INCIDENT_SUNLIGHT_BRNO_H

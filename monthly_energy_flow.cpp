/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include <iostream>
#include "monthly_energy_flow.h"
#include "solar_energy_source.h"

MonthlyEnergyFlow::MonthlyEnergyFlow(
	YearCycle *yearCycle,
	double throughput,
	unsigned collectorArea,
	angle degree
)
{
	this->yearCycle = yearCycle;
	this->throughput = throughput;
	this->collectorArea = collectorArea;
	this->degree = degree;
}

void MonthlyEnergyFlow::Behavior()
{
	//calculate once for each month
	while (1)
	{
		yearCycle->setNewMonth();
		auto month = yearCycle->getCurrentMonth();
		double collectorEfficiency = throughput - collectorArea * ((30 - yearCycle->MEAN_TEMPERATURE_OF_SUNLIGHT_BRNO[month]) / yearCycle->MEAN_INTENSITY_OF_SUNLIGHT_BRNO[degree][month]);
		double realIncidentEnergy = yearCycle->SUNLIGHT_RATIO_BRNO[month] * yearCycle->TEORETICAL_CAPTURED_SUNLIGHT_BRNO[degree][month];
		double realCapturedEnergy = collectorEfficiency * realIncidentEnergy;
		double dailyEnergyProduct = realCapturedEnergy * collectorArea;

		for (unsigned day = 0; day < yearCycle->getNumberOfDaysForCurrentMonth(); ++day)
		{
			auto dayProcess = new SolarEnergySource(
				yearCycle,
				dailyEnergyProduct
			);
			dayProcess->Activate(Time + day);
		}

		Wait(yearCycle->getNumberOfDaysForCurrentMonth());
	}
}


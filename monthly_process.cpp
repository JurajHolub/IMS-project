/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include <iostream>
#include "monthly_process.h"
#include "daily_process.h"
#include "sunlight_brno.h"
#include "mean_intensity_of_sunlight_brno.h"
#include "teoretical_incident_sunlight_brno.h"

MonthlyProcess::MonthlyProcess(
		YearCycle *yearCycle,
		Statistics *stat,
		double throughput,
		unsigned collectorArea,
		double requiredHeat,
		Angle degree
)
{
	this->yearCycle = yearCycle;
	this->stat = stat;
	this->throughput = throughput;
	this->collectorArea = collectorArea;
	this->requiredHeat = requiredHeat;
	this->degree = degree;
}

void MonthlyProcess::Behavior()
{
	//calculate once for each month
	while (1)
	{
		yearCycle->setNewMonth();
		auto month = yearCycle->getCurrentMonth();
		double collectorEfficiency = throughput - collectorArea * ((degree - SunlightBrno::getMeanTemperate(month)) / MeanIntensityOfSunlightBrno::get(month, degree));
		double realIncidentEnergy = SunlightBrno::getRatio(month) * TeoreticalIncidentSunlightBrno::get(month, degree);
		double realCapturedEnergy = collectorEfficiency * realIncidentEnergy;
		double dailyEnergyProduct = realCapturedEnergy * collectorArea;

		for (unsigned day = 0; day < yearCycle->getNumberOfDaysForCurrentMonth(); ++day)
		{
			auto dayProcess = new DayilyProcess(
				yearCycle,
				stat,
				dailyEnergyProduct,
				requiredHeat
			);
			dayProcess->Activate(Time + day);
		}

		Wait(yearCycle->getNumberOfDaysForCurrentMonth());
	}
}


/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "year_cycle.h"
#include <iostream>

YearCycle::YearCycle(unsigned numberOfProcessesPerDay)
{
	year = 0;
	currentMonth = Decembre;
	this->numberOfProcessesPerDay = numberOfProcessesPerDay;
}

YearCycle::Months YearCycle::getCurrentMonth()
{
	return currentMonth;
}

YearCycle::Months YearCycle::setNewMonth()
{
	currentMonth = Months((currentMonth + 1) % (Decembre + 1));
	if (currentMonth == January)
	{
		year++;
		//std::cout << "Simulate " << year << ". year...\n";
	}
}

unsigned YearCycle::getNumberOfDaysForCurrentMonth()
{
	return numberOfMonthDay[currentMonth];
}

unsigned YearCycle::getCurrentSolarEnergyProduction()
{
	return monthlySolarProduction[currentMonth] * numberOfProcessesPerDay;
}

unsigned YearCycle::getNumberOfYears()
{
	return year;
}

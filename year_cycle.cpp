/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "year_cycle.h"

YearCycle::YearCycle()
{
	currentMonth = Decembre;
}

YearCycle::Months YearCycle::getCurrentMonth()
{
	return currentMonth;
}

YearCycle::Months YearCycle::setNewMonth()
{
	currentMonth = Months((currentMonth + 1) % (Decembre + 1));
}

unsigned YearCycle::getNumberOfDaysForCurrentMonth()
{
	return numberOfMonthDay[currentMonth];
}

unsigned YearCycle::getCurrentSolarEnergyProduction()
{
	return monthlySolarProduction[currentMonth];
}

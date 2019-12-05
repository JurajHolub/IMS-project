/**
 * @project VUT FIT - IMS project
 * @author Juraj Holub		<xholub40@stud.fit.vutbr.cz>
 * @author Matej Parobek	<xparob00@stud.fit.vutbr.cz>
 * @date November 2019
 */

#include "year_cycle.h"
#include <iostream>

YearCycle::YearCycle()
{
	year = 0;
	currentMonth = Decembre;
}

Months YearCycle::getCurrentMonth()
{
	return currentMonth;
}

Months YearCycle::setNewMonth()
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
unsigned YearCycle::getNumberOfYears()
{
	return year;
}

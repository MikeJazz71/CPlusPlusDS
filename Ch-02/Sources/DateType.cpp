
#ifndef DATATYPE_CPP
#define DATATYPE_CPP

//	C++ Plus Data Structures, Chapter 2.

//	Class Implementation.

#include "../Headers/DateType.h"

DateType::DateType(void)
{
	year = month = day = 0;
}

void DateType::initialize(int newYear, int newMonth, int newDay)
{
	year = newYear;
	month = newMonth;
	day = newDay;
}

int DateType::getYear(void) const
{
	return year;
}

int DateType::getMonth(void) const
{
	return month;
}

int DateType::getDay(void) const
{
	return day;
}

#endif //DATATYPE_CPP

#ifndef DATATYPE_H
#define DATATYPE_H

//	C++ Plus Data Structures, Chapter 2.

//	Class Specification.

class DateType
{

public:
	DateType(void);
	void initialize(int, int, int);
	int getYear(void) const;
	int getMonth(void) const;
	int getDay(void) const;

private:
	int year;
	int month;
	int day;
	
};

#endif //DATATYPE_H
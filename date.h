#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace::std;

class Date
{

private:
	int month;
	int day;
	int year;

public:
	Date();
	Date(string date);
	static bool overlap(Date start1, Date end1, Date start2, Date end2);
	bool operator>(const Date x);
	
	void setDate(string arg);
	void setMonth(int newMonth);
	void setDay(int newDay);
	void setYear(int newYear);

	int getMonth();
	int getDay();
	int getYear();
	bool isLeapYear();

};

#endif
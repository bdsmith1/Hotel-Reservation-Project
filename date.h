#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iosmanip>
#include <string>

using namespace::std;
using std::string;
using std::ostream;
using std::setw;

class Date
{

private:
	int month;
	int day;
	int year;

public:
	Date(string date);
	//Date(int month, int day, int year);
	bool overlap(Date start1, Date end1, Date start2, Date end2);
	bool operator>(const Date x);
	
	
	void displayDate(ostream& out);
	void setMonth(int newMonth);
	void setDay(int newDay);
	void setYear(int newYear);

	int getMonth();
	int getDay();
	int getYear();
	bool isLeapYear();

};

#endif

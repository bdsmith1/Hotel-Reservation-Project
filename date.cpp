#include "date.h"
#include <sstream>

Date::Date(string date)
{
	istringstream buf(date);
	int mon,day,year;
	char c1,c2;
	if( buf >> mon >> c1 >> day >> c2 >> year && c1=='/' && c2=='/')
	{
		setMonth(mon);
		setDay(day);
		setYear(year);
	}
}

bool Date::overlap(Date start1, Date end1, Date start2, Date end2)
{
	/*
	cout << "start1 "<< start1.month << start1.day << start1.year << endl;
	cout << "end1 "<< end1.month << end1.day << end1.year << endl;
	cout << "start2 "<< start2.month << start2.day << start2.year << endl;
	cout << "end2 "<< end2.month << end2.day << end2.year << endl;*/
	if(start1 > start2 && end2 > start1 || end1 > start2 && end2 > end1)// start1 is b/n start2 & end2. end1 is b/n start2 & end2. 	
		return true;

	return false;

}
bool Date::operator>(const Date x)
{
	if(this->year > x.year || this->year == x.year && this->month > x.month || this->year == x.year && this->month == x.month && this->day > x.day || 
		this->year == x.year && this->month == x.month && this->day == x.day)
		return true;

	cout << "here" << endl;
	return false;
}
Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}
int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}

bool Date::isLeapYear()
{
	if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 != 0))
		return true;
	else
		return false;
}

void Date::setDay(int newDay)
{
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if(newDay < 1 || newDay > 31)
			this->day = day;
		else
			this->day = newDay;

	if(month == 4 || month == 6 || month == 9 || month == 11)
		if(newDay < 1 || newDay > 30)
			this->day = day;
		else
			this->day = newDay;

	if(month == 2 && isLeapYear() == false)
		if(newDay < 1 || newDay > 28)
			this->day = day;
		else
			this->day = newDay;

	if(month == 2 && isLeapYear() == true)
		if(newDay < 1 || newDay >31)
			this->day = day;
		else
			this->day = newDay;
}

void Date::setMonth(int newMonth)
{
	if(newMonth < 1 || newMonth > 12)
		this->month = month;
	else
		this->month = newMonth;
}

void Date::setYear(int newYear)
{
	if(newYear < 1)
		this->year = year;
	else
		this->year = newYear;
}
void Date::setDate(string arg)
{
	istringstream buf(arg);
	int mon,day,year;
	char c1,c2;
	if( buf >> mon >> c1 >> day >> c2 >> year && c1=='/' && c2=='/')
	{
		setMonth(mon);
		setDay(day);
		setYear(year);
	}
	else return;


}

#include "date.h"
#include "stringstream"

Date::Date(string date)
{
	stringstream out;
	string temp;
	out << date;
	out >> temp;
	month = atoi(temp.c_str());
	out << date;
	out >> temp;
	day = atoi(temp.c_str());
	out << date;
	out >> temp;
	year = atoi(temp.c_str());
}

bool Date::overlap(Date start1, Date end1, Date start2, Date end2)
{
	if(start1 > start2 && end2 > start1 || end1 > start2 && end2 > end1)// start1 is b/n start2 & end2. end1 is b/n start2 & end2. 	
		return true;

	return false;

}
bool Date::operator>(const Date x)
{
	if(this.year > x.year || this.year == x.year && this.month > x.month || this.year = x.year && this.month == x.month && 			this.day > x.day)
		return true;

	return false;
}
/*(
Date::Date(int month, int day, int year)
{
	if(year < 1)
		this->year = 2013;
	else
		this->year = year;

	if(month < 1 || month > 12)
		this->month = 1;
	else
		this->month = month;

	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if(day < 1 || day > 31)
			this->day = 1;
		else
			this->day = day;

	if(month == 4 || month == 6 || month == 9 || month == 11)
		if(day < 1 || day > 30)
			this->day = 1;
		else
			this->day = day;

	if(month == 2 && isLeapYear() == false)
		if(day < 1 || day > 28)
			this->day = 1;
		else
			this->day = day;

	if(month == 2 && isLeapYear() == true)
		if(day < 1 || day >31)
			this->day = 1;
		else
			this->day = day;
}
*/
void Date::displayDate()
{
	out << setw(2) << month << "/" << setw(2) << day << "/" << year;
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

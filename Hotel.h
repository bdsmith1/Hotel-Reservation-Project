#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
#include "date.h"


class Hotel
{
public:
	Hotel();
	Hotel(int kingx, int queenx, int twinx);
	void clear(); // Supposed to free up room after check-out
	void list();
	void list(string type);
	bool reserve(string roomType, string name, string creditcard, string start, string end); // List of parameters.
	bool clear(string name);
private:

	int king;
	int queen;
	int twin;
	bool isAvailable(string roomType, Date start, Date end);

	

};
#endif

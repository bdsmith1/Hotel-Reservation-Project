#ifndef

#include <iostream>
#include <string>
#include <iomanip>


class Hotel
{
public:
	Hotel();
	Hotel(int kingx, int queenx, int twinx);
	void clear(); // Supposed to free up room after check-out
	void List();
	void List(string type);
	bool reserve(string roomType, string name, string creditcard, Date start, Date end); // List of parameters.
private:

	int king;
	int queen;
	int twin;
	bool isAvailable(string roomType, Date start, Date end);

	

	}
#endif

#include "Hotel.h"
#include <iostream>
#include <fstream>
using namespace std;

Hotel::Hotel()
{
	king = 0;
	queen= 0;
	twin = 0;

}

Hotel::Hotel(int kingx, int queenx, int twinx)
{
	king = kingx;
	queen= queenx;
	twin = twinx;
	fstream in("roomlist.txt", fstream::in);// code for inputing the text file with room....
	in << "Type\tName\t\t\tCredit Card\tStart Date\tEnd Date\n";
	in.close();
	
}

void Hotel::List()
{
	fstream in("roomlist.txt", fstream::in);
	do
	{
	cout << in.getLine();
	}while(in);
}
void Hotel::List(string type)
{
 
	fstream in("roomlist.txt", fstream::in); //reads in the .txt file
	string test;
	in >> test;
	while(in)
	{
	if(type == test) // if it's the same type(string) reads it in.
		cout << in.getline() << endl;

	in >> test;
	}
	
}
bool Hotel::reserve(string roomType, string name, string creditcard, Date start, Date end) // List of parameters.
{
	fstream in("roomlist.txt", fstream::app);
	bool available;
	available = isAvailabe(roomType, start, end);
	if(available)
		in << roomType << "\t" << name << "\t" << creditcard << "\t" << start << "\t" << end << "\n";
}	
bool Hotel::isAvailable(string roomType, Date start, Date end)
{
	if ( start!= end)
		true;
	
}




#include "Hotel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
	fstream out("roomlist.txt", fstream::out);// code for inputing the text file with room....
	out << "Type\tName\t\tCredit Card\tStart Date\tEnd Date\n";
	out.close();
	
}

void Hotel::list()
{
	fstream in("roomlist.txt", fstream::in);
	string line;
	while(!in.eof())
	{
		getline(in,line);
		cout << line << endl;
	}
}
void Hotel::list(string type)
{
	fstream in("roomlist.txt", fstream::in); //reads in the .txt file
	string test,line;
	in >> test;
	while(in)
	{
		if(type == test) // if it's the same type(string) reads it in.
		{
			getline(in,line);
			cout << line << endl;
		}
		in >> test;
	}
	
}
bool Hotel::reserve(string roomType, string name, string creditcard, string start, string end) // List of parameters.
{
	bool available;
	Date start1(start);
	Date end1(end);

	if(creditcard.size() != 16)
	{
		cout << "Invalid Credit Card" << endl;
		return false;
	}
	
	available = isAvailable(roomType, start1, end1);
	if(available)
	{
		fstream in("roomlist.txt", fstream::app);
		in << roomType << "\t" << name << "\t" << creditcard << "\t" << start << "\t" << end << "\n";
		return true;
	}
	return false;
}	
bool Hotel::isAvailable(string roomType, Date start, Date end)
{
	int num;
	string startdate,enddate;
	Date start2,end2;
	if(roomType == "king")
		num = king;
	else if(roomType == "queen")
		num = queen;
	else if(roomType == "twin")
		num = twin;
	else return false;
	
	fstream in("roomlist.txt", fstream::in);
	string compare;
	string ignore;
	in >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore;
	while(!in.eof())
	{		
		if(num==0)
			return false;
		in >> compare >> startdate >> startdate >> startdate >> enddate;
		start2.setDate(startdate);
		end2.setDate(enddate);
		if(compare == roomType)
		{
			cout << num << endl;
			if(Date::overlap(start,end,start2,end2))
				num--;
		}
	}
	return true;
}
bool Hotel::clear(string name)
{
	fstream in("roomlist.txt", fstream::in);
	bool found = 0;
	stringstream out;
	string compare;
	string type,card,date1,date2,ignore;
	getline(in,ignore);
	out << ignore << endl;
	while(!in.eof())
	{
		in >> type >> compare >> card >> date1 >> date2;
		if(compare == name)
		{
			found = true;
			continue;
		}
		out << type << " " << compare << " " << card << " " << date1 << " " << date2 << endl;
	}
	if(!found)
	{
		return false;
	}
	in.close();
	fstream output("roomlist.txt", fstream::out);
	output << out.str();
	return true;
}




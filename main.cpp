#include "date.h"
#include "Hotel.h"
using namespace std;

int main(int argc, char* argv[])
{
	string king, queen, twin;
	int num1,num2,num3;
	king = argv[1];
	queen = argv[2];
	twin = argv[3];
	num1 = atoi(king.c_str());
	num2 = atoi(queen.c_str());
	num3 = atoi(twin.c_str());
	Hotel myhotel(num1,num2,num3);
	string command;
	string param[5];

	while(1)
	{
		cin >> command;
		if(command == "list")
			myhotel.list();
		else if(command == "reserve")
		{
			cin >> param[0] >> param[1] >> param[2] >> param[3] >> param[4];
			if(myhotel.reserve(param[0],param[1],param[2],param[3],param[4]))
				cout << "Reservation completed" << endl;
			else
				cout << "Room type: " << param[0] << " is not available for the dates entered" << endl;
		}
		else if(command == "clear")
		{
			cin >> param[0];
			myhotel.clear(param[0]);
		}
		else
		{
			cout << "Command not found" << endl;
		}
	}

	return 0;
}
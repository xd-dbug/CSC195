#include "Main.h"
#include "DataBase.h"
#include <iostream>
using namespace std;

int main()
{
DataBase db;
bool quit = false;
while (!quit)
{
	cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int type;
		cout << "Enter the type of song (0 for Rock, 1 for HipHop): ";
		cin >> type;
		db.Create(static_cast<BaseClass::eType>(type));
		break;
	}
	case 2:
		db.DisplayAll();
		break;
	case 3:
	{
		string name;
		cout << "Enter the name of the song: ";
		cin >> name;
		db.Display(name);
		break;
	}
	case 4:
	{
		std::cout << "Enter type (0 for Rock, 1 for HipHop): ";
		int t;
		std::cin >> t;
		db.Display(static_cast<BaseClass::eType>(t));
		break;
	}
	case 5:
		quit = true;
		break;
	}
}

return 0;
}

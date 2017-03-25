#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
void PathToHome(Map &map);

int main()
{
	Map map = Map("Home");

	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go West" << endl;
		cout << "6) Path To Home" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		switch (choice)
		{
			case 0: break;
			case 1: cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo(); break;
			case 2: GoNorth(map); break;
			case 3: GoEast(map); break;
			case 4: GoSouth(map); break;
			case 5: GoWest(map); break;
			case 6: system("cls");  cout << map.GetPathBackToHome() << endl; break;
			default: cout << "Enter a valid option"; break;
		}
		system("pause");
	}

	return 0;
}


void GoNorth(Map &map)
{
	Location *newLocation = map.CurrentLocation->North;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY + 1;
		Location *existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			map.MapLayout("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
			map.CurrentLocation->North = existing;
			existing->South = map.CurrentLocation;
			newLocation = existing;
			map.Move(existing);
		}
		
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
		newLocation->South = map.CurrentLocation;
		map.Move(newLocation);
	}
	return;
}
void GoSouth(Map &map)
{
	Location *newLocation = map.CurrentLocation->South;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY - 1;
		Location *existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			map.MapLayout("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
			map.CurrentLocation->South = existing;
			existing->North = map.CurrentLocation;
			map.Move(existing);
		}	
		
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
		newLocation->North = map.CurrentLocation;
		map.Move(newLocation);
	}
	return;
}
void GoEast(Map &map)
{
	Location *newLocation = map.CurrentLocation->East;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr)
	{
		int newX = currentX + 1;
		int newY = currentY;
		Location *existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			map.MapLayout("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
			map.CurrentLocation->East = existing;
			existing->West = map.CurrentLocation;
			map.Move(existing);
		}
		
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
		newLocation->West = map.CurrentLocation;
		map.Move(newLocation);
	}
	return;
}
void GoWest(Map &map)
{
	Location *newLocation = map.CurrentLocation->West;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr)
	{
		int newX = currentX - 1;
		int newY = currentY;
		Location *existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			map.MapLayout("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
			map.CurrentLocation->West = existing;
			existing->East = map.CurrentLocation;
			newLocation = existing;
		}

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
		newLocation->East = map.CurrentLocation;
		map.Move(newLocation);
	}
	return;
}
void PathToHome(Map &map)
{

}
#pragma once
#include <stack>
#include "Location.h"
class Map
{
private:
	std::stack<Location *> _locationsVisited;
public:
	Map(std::string startingLocationName);
	~Map();

	Location *_currentLocation = nullptr;
	std::string GetPathBackToHome();
	void Move(Location *newLocation);
};


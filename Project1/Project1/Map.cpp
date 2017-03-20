#include "Map.h"
#include <string>


Map::Map(std::string startingLocationName)
{
	_currentLocation = new Location(startingLocationName);
}

Map::~Map()
{
}

void Map::Move(Location * newLocation)
{
	_locationsVisited.push(newLocation);
	_currentLocation = newLocation;
}

std::string Map::GetPathBackToHome()
{
	return "TODO: Implement this";
}
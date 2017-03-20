#include "Map.h"


Map::Map(std::string startLocationName)
{
	CurrentLocation = new Location(startLocationName);
}


Map::~Map()
{
}

void Map::Move(Location *newLocation)
{
	_locationsVisited.push(newLocation);
	CurrentLocation = newLocation;
}

std::string Map::GetPathBackToHome()
{
	return "TODO: Implement this";
}
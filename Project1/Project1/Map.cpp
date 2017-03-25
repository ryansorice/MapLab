#include "Map.h"


Map::Map(std::string startLocationName)
{
	std::string hash = "(0,0)";
	CurrentLocation = new Location(startLocationName, 0, 0);
	_locationsVisited.push(CurrentLocation);
	_mapLookup[hash] = CurrentLocation;
}


Map::~Map()
{
}

void Map::Move(Location *newLocation)
{
	std::string hash = "(" + std::to_string(CurrentLocation->getX()) + ", " + std::to_string(CurrentLocation->getY()) + ")";
	_mapLookup[hash] = CurrentLocation;
	_locationsVisited.push(newLocation);
	CurrentLocation = newLocation;
}

Location * Map::LookupLocationOnMap(int x, int y)
{
	std::string hash = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
	return _mapLookup[hash];
}

void Map::MapLayout(std::string coordinates, Location * locationPtr)
{
	_mapLookup[coordinates] = locationPtr;
}


std::string Map::GetPathBackToHome()
{
	std::string result = "Path back to Home:\n";

	while (_locationsVisited.size() != 0)
	{
		result += _locationsVisited.top()->DisplayLocationInfo();
		_locationsVisited.pop();
	}
	return result;
}
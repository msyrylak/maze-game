#include "stdafx.h"


Room::Room()
{
	setNorth(nullptr);
	setSouth(nullptr);
	setEast(nullptr);
	setWest(nullptr);
	link = nullptr;
}


Room::~Room()
{
}

void Room::setNorth(Room* room)
{
	north = room;
}

void Room::setSouth(Room* room)
{
	south = room;
}

void Room::setEast(Room* room)
{
	east = room;
}

void Room::setWest(Room* room)
{
	west = room;
}

Room* Room::getNorth()
{
	return north;
}

Room* Room::getSouth()
{
	return south;
}

Room* Room::getEast()
{
	return east;
}

Room* Room::getWest()
{
	return west;
}


void Room::setLink(Room* node)
{
	link = node;
}

Room* Room::getLink()
{
	return link;
}
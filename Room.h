#ifndef ROOM_H
#define ROOM_H

#include "stdafx.h"

class Room
{
	//class Room represents a node in a linked list

public:
	Room();
	~Room();

	void setNorth(Room* room);
	void setSouth(Room* room);
	void setEast(Room* room);
	void setWest(Room* room);

	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();


private:
	//directions
	Room* north;
	Room* south;
	Room* east;
	Room* west;
};

#endif

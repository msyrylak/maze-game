#ifndef ROOM_H
#define ROOM_H
#include "MazeGamePCH.h"

class Room
{
	//class Room represents a node in a graph

public:

	Room();
	~Room();

	void setNorth(Room* room);
	void setSouth(Room* room);
	void setEast(Room* room);
	void setWest(Room* room);
	void setLink(Room* room);

	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();
	Room* getLink();

private:
	//directions
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	Room* link;
};

#endif

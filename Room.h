#ifndef ROOM_H
#define ROOM_H


#include "stdafx.h"


class Node
{
public:
	Node* link;

	Node()
	{
		link = nullptr;
	}

	void setLink(Node* node)
	{
		link = node;
	}

	Node* getLink()
	{
		return link;
	}
};


class Room : public Node
{
	//class Room represents a node in a graph

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

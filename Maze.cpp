#include "stdafx.h"



Maze::Maze()
{

}


Maze::~Maze()
{
}

void Maze::initRoomList()
{
	for(int i = 0; i < 10; i++)
	{
		Room* r = new Room;
		r->setLink(roomList);
		roomList = r;
	}
}
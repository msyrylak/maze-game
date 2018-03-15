#include "stdafx.h"



Maze::Maze()
{

}


Maze::~Maze()
{
}


Room* Maze::initRoomList()
{
	for(int i = 0; i < 10; i++)
	{
		Room* r = new Room;
		r->setLink(roomList);
		roomList = r;
	}
	return roomList;
}

void Maze::printRoomList()
{
	Room* current;
	current = roomList;

	while(current != nullptr)
	{
		std::cout << current << std::endl;
		current = current->getLink();
	}

}

Room* Maze::findRoom(int i)
{
	if(i < 0)
	{
		std::cout << "Invalid index!" << std::endl;
		return nullptr;
	}

	Room* current = roomList;
	int count = 0;
	
	while(current)
	{
		if(count == i)
		{
			break;
		}
		current = current->getLink();
		count++;
	}

	return current;
}
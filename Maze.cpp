#include "stdafx.h"



Maze::Maze()
{

}


Maze::~Maze()
{
	deleteRoomList();
}


Room* Maze::initRoomList()
{
	for(int i = 0; i < 15; i++)
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

	while(current)
	{
		std::cout << current << std::endl;
		current = current->getLink();
	}
}

Room* Maze::findRoom(int i)
{
	if(i < 0)
	{
		//std::cout << "Invalid index!" << std::endl;
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

void Maze::addEdges(Room* current, int n, int s, int e, int w)
{
	if(current)
	{
		current->setNorth(findRoom(n));
		current->setSouth(findRoom(s));
		current->setEast(findRoom(e));
		current->setWest(findRoom(w));
	}
}

void Maze::deleteRoomList()
{
	Room* current;
	Room* next;
	current = roomList;

	while(current)
	{
		next = current->getLink();
		delete current;
		current = next;
		std::cout << "Deleted!" << std::endl;
	}
	roomList = nullptr;
}

int Maze::roomNumber(Room* current)
{
	Room* temp;
	temp = roomList;
	int count = 0;

	while(temp)
	{
		if(current == temp)
		{
			return count;
		}
		temp = temp->getLink();
		count++;
	}
}

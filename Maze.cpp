#include "MazeGamePCH.h"

Maze::Maze()
{

}

Maze::~Maze()
{
	deleteRoomList();
}

void Maze::setRoomList(Room* _room)
{
	roomList = _room;
}

Room* Maze::getRoomList()
{
	return roomList;
}


Room* Maze::initRoomList()
{
	for(int i = 0; i < 15; i++)
	{
		addToList(new Room());
	}
	return roomList;
}

void Maze::addToList(Room* room)
{
	if(!roomList)
	{
		roomList = room;
	}
	else
	{
		Room* current = roomList;
		while(current)
		{
			if(!current->getLink())
			{
				current->setLink(room);
				break;
			}
			current = current->getLink();
		}
	}
}

Room* Maze::findRoom(int i)
{
	if(i < 0)
	{
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
	}
	roomList = nullptr;
}

int Maze::getRoomNumber(Room* current)
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

bool Maze::checkIfEndRoom(int roomNumber)
{
	if(roomNumber == (15 - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

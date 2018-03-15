#ifndef MAZE_H
#define MAZE_H
#include "stdafx.h"

class Room;

class Maze
{
public:
	Maze();
	~Maze();

	Room* initRoomList();
	void printRoomList();
	Room* findRoom(int i);

	Room* roomList;
};

#endif // !MAZE_H



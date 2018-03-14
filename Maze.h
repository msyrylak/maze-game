#ifndef MAZE_H
#define MAZE_H
#include "stdafx.h"

class Room;

class Maze
{
public:
	Maze();
	~Maze();

	void initRoomList();

	Room* roomList;
};

#endif // !MAZE_H



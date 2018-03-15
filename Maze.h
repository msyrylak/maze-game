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
	Room* findRoom(int i);
	void printRoomList();
	void addEdges(Room* _current, int n, int s, int e, int w);
	void deleteRoomList();
	Room* roomList;
};

#endif // !MAZE_H



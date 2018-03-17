#ifndef MAZE_H
#define MAZE_H
#include "stdafx.h"

class Room;

class Maze
{
public:
	Maze();
	~Maze();

	void setRoomList(Room*);
	Room* getRoomList();
	Room* initRoomList();
	Room* findRoom(int i);
	void printRoomList();
	void addEdges(Room* _current, int n, int s, int e, int w);
	void deleteRoomList();
	int roomNumber(Room* _current);

private:
	Room* roomList;

	void addToList(Room* room);

};

#endif // !MAZE_H



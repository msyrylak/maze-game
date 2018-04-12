#ifndef MAZE_H
#define MAZE_H
#include "MazeGamePCH.h"

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
	int getRoomNumber(Room* _current);
	bool checkIfEndRoom(int roomNumber);

private:
	Room* roomList;

	void addToList(Room* room);

};

#endif // !MAZE_H



#include "stdafx.h"

using namespace std;


int main()
{
	int r, n, s, e, w;
	Maze m;
	m.initRoomList();
	
	Room* current = m.roomList;
	Room* next;

	ifstream roomsFile;
	roomsFile.open("roomNum.txt");
	if(!roomsFile)
	{
		cout << "File not found!";
		system("pause");
	}
	else
	{
		while(roomsFile >> r >> n >> s >> e >> w)
		{
			m.addEdges(m.findRoom(r-1), n-1, s-1, e-1, w-1);
		}
	}

	bool running = true;

	while(running)
	{
		cout << "You are in the room number: " << m.roomNumber(current) + 1 << endl;
		cout << "Which direction do you want to go?" << endl;
		cout << "(n)orth, (s)outh, (e)ast, (w)est or (esc)ape" << endl;

		next = current;

		switch(_getch())
		{
		case 'n':
			next = current->getNorth();
			break;

		case 's':
			next = current->getSouth();
			break;

		case 'e':
			next = current->getEast();
			break;

		case 'w':
			next = current->getWest();
			break;

		case 27:
			running = false;
			break;

		default:
			break;
		}
		if(next)
		{
			current = next;
		}
		else
		{
			cout << "There's nothing behind this door!" << endl;
		}
	}
	m.deleteRoomList();
	return 0;
}
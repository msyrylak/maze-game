#include "stdafx.h"

int main()
{
	int r, n, s, e, w;
	int count = 0;

	Maze m;
	m.initRoomList();
	
	Room* current = m.getRoomList();
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
		//while(getline(roomsFile, c))
		//{
		//	count++;
		//}

		//cout << "Lines count: " << count << endl;

		while(roomsFile >> r >> n >> s >> e >> w)
		{
			m.addEdges(m.findRoom(r-1), n-1, s-1, e-1, w-1);
		}
	}
	//roomsFile.close();

	bool running = true;

	while(running)
	{
		cout << "You are in the room number: " << m.roomNumber(current) + 1 << endl;
		m.roomCheck(m.roomNumber(current));
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
			cout << " " << endl;
			cout << "There's nothing behind this door!" << endl;
		}
		cout << " " << endl;

	}
	m.deleteRoomList();
	return 0;
}
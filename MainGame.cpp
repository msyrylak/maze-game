#include "stdafx.h"

using namespace std;


int main()
{
	int r, n, s, e, w;
	Maze m;
	m.initRoomList();

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
	



	//m.findRoom(5);
    //m.addEdges(m.findRoom(6), 2, 5, 0, 7);

	m.deleteRoomList();


	

	//do
	//{
	//	cout << "Welcome to the Maze Game!" << endl;






	//} while (true);

	return 0;
}
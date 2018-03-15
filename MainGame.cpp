#include "stdafx.h"

using namespace std;


int main()
{

	Maze m;
	m.initRoomList();

	//m.printRoomList();

	m.findRoom(5);
	m.findRoom(15);
	m.findRoom(-7);


	system("pause");

	//do
	//{
	//	cout << "Welcome to the Maze Game!" << endl;






	//} while (true);

	return 0;
}
#include "MazeGamePCH.h"

int main()
{
	int room, north, south, east, west;
	int count = 0;
	char c;

	Maze m;

	Room* current = new Room();
	Room* next;

	ifstream roomsFile;

	enum
	{
		INITIALIZE,
		RUNNING,
		WIN,
		QUIT
	} gState;

	gState = INITIALIZE;



	while(gState != QUIT)
	{
		switch(gState)
		{
		case INITIALIZE:

			m.initRoomList();

			current = m.getRoomList();

			roomsFile.open("roomNum.txt");
			if(roomsFile)
			{
				while(roomsFile >> room >> north >> south >> east >> west)
				{
					m.addEdges(m.findRoom(room-1), north-1, south-1, east-1, west-1);
				}
			}
			else
			{
				cout << "File not found!";
				system("pause");
			}
			roomsFile.close();

			cout << "Welcome to The Maze Game!" << endl;
			cout << "Are you ready to play? Press 's' or Enter to start or 'q' to quit.\n" << endl;

			c = _getch();
			if(c == 's' || '/n')
			{
				gState = RUNNING;
			}
			else if(c == 'q')
			{
				gState = QUIT;
			}
			else
			{
				cout << "Wrong key! Try again!\n" << endl;
			};
			break;

		case RUNNING:
			while(gState == RUNNING)
			{
				cout << "You are in the room number: " << m.getRoomNumber(current) + 1 << endl;

				bool checkEnded = m.checkIfEndRoom(m.getRoomNumber(current));
				
				if(checkEnded)
				{
					gState = WIN;
				}
				else
				{
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
						gState = QUIT;
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
			};
			break;

		case WIN:

			cout << " " << endl;
			cout << "    _____                            _         _       _   _                 " << endl;
			cout << "   / ____|                          | |       | |     | | (_)                " << endl;
			cout << "  | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___  " << endl;
			cout << "  | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __|" << endl;
			cout << "  | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\" << endl;
			cout << "   \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___/" << endl;
			cout << "                      __/ |                                                  " << endl;
			cout << "                     |___/                                                   " << endl;
			cout << " " << endl;
			cout << "Congratulations, you've reached the end of the maze!" << endl;
			cout << "Do you want to play again? [y/n]\n" << endl;

			c = _getch();

			if(c == 'y')
			{
				gState = INITIALIZE;
			}
			else if(c == 'n')
			{
				gState = QUIT;
			}
			else
			{
				cout << "Wrong key! Try again!\n" << endl;
			};
			break;

		case QUIT:
			m.deleteRoomList();
			break;
		default:
			break;
		}
	}
	return 0;
}
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include "Game.h"
#include "Bot.h"
using namespace std;


//створюємо бота
IPlayer* InitBot()
{
	return new Bot2();
}
//створюємо людину
IPlayer* InitHuman()
{
	return new Human();
}


int main()
{
	srand((unsigned int)time(nullptr));
	bool start = true;
	char ch;
	IPlayer* p_player1;
	IPlayer* p_player2;
	char player1;
	char player2;
	while (start)
	{
		cout << "Start game(1)" << endl << "Quit(0)" << endl;
		ch = _getch();
		if (ch == '1')
		{
			while (start)
			{
				system("CLS");
				cout << "Choose player_1 charackteristic:"  << endl << "Bot(1)" << endl << "Human(2)" << endl;
				player1 = _getch();
				if (player1 == '1')
				{
					p_player1 = InitBot();
				}
				else if (player1 == '2')
				{
					p_player1 = InitHuman();
				}
				else
				{
					exit(0);
				}
				system("CLS");
				cout << "Choose player_2 charackteristic:" << endl << "Bot(1)" << endl << "Human(2)" << endl;
				player2 = _getch();
				if (player2 == '1')
				{
					p_player2 = InitBot();
				}
				else if (player2 == '2')
				{
					p_player2 = InitHuman();
				}
				else
				{
					exit(0);
				}			
				system("CLS");
				cout << "Game is started" << endl;
				Game g;
				g.SetPlayers(p_player1, p_player2);
				g.Start();
				g.PlayRound();
				g.Finish();
				delete p_player1;
				delete p_player2;
				return 0;
			}

		}
		else
		{
			system("CLS");
			cout << "See ya next time" << endl;
			exit(0);
		}

	}
	
}

	
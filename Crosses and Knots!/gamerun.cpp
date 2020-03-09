/*
Crosses and Knots By Gokul Viswanath.
Just a program to start implementing algorithms in simple games.

Patch Notes-

1.0 - Vanilla version, stil with lots of bugs. Will be fixed in 1.1.

1.1 - Most bugs fixed, still have some in win checking.

1.2 - fixed win checking problems

1.3 - Major graphics changes. The grid is made bigger for the players to see the characters.

1.4 - Grid numbers will now be shown in-game and will change into X or O once the grid is taken.

1.5 - Instead of hitting enter(std::cin) the player only has to tap on the letter on the keygrid
(using _getch() ). Poses a problem if the player has second thoughts before making the decision.
Will think of adding an undo option for a limited time before next move.

1.6 -	Main menu added with opponent choice
Player can now play against another human or againt PC (AI). (programmed using minimax algorithm)
For now, playing against PC will only result in a draw or loss for the player.





*/

#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<conio.h>
#include <iomanip>
#include <algorithm>
#include <limits>
#include "gamerun.h"



gamerun::gamerun()
{
	returnval();

	player = 1;
	int b;
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++) {

		b = (i * 10) + j;
		board[i][j] = b;

	}

	mainmenu();

}


void gamerun::multigame() {

	for (c = 0; c < 9; c++) {

		system("cls");
		mainscreen();

		// human move
		if (c % 2 == 0)
		{
			std::cout << "\n\n\t\tPlace your X, Player 1.";
			getHumanMove();

			if (HasWon(who::human))
			{
				system("cls");
				mainscreen();
				std::cout << "\n\n\nPlayer 1 wins!! Good game!";
				break;
			}
		}
		else
		{
			std::cout << "\n\n\t\tPlace your O, Player 2.";
			getHumanMove();

			if (HasWon(who::comp))
			{
				system("cls");
				mainscreen();
				std::cout << "\n\n\nPlayer 2 wins!! Good game!";
				break;
			}
		}

		if (isTie())
		{
			system("cls");
			mainscreen();
			std::cout << "\n\nIt's a draw! "; //if nobody wins

			break;
		}

	}//loop
	ending();

}




void gamerun::ending() {

	std::cout << "\n\nDo you want to play more or exit? Enter 'M' or 'E' as per your choice- ";

	char choice;
	std::cin >> choice;

	if (choice == 'm' || choice == 'M') {
		system("cls");
		returnval();
	}
	else if (choice == 'e' || choice == 'E') {
		std::cout << "\n\nThank you for playing! Exiting...\n\n";
		exit(0);
	}
}

void gamerun::mainscreen() {

	std::cout << "\n\t\t\t\t\t--CROSSES AND KNOTS--\n\n\t\t\t\tPLAYER 1: X\t\tPLAYER 2: O";

	std::cout << "\n\n\n\n\t\t\t\t     |     |     \t\t\t\t\t      |      |      " << std::endl;
	std::cout << "\t\t\t\t  " << static_cast<char>(grid[0][0]) << "  |  " << static_cast<char>(grid[0][1]) << "  |  " << static_cast<char>(grid[0][2]);
	std::cout << "\t\t\t\t\t\t  00  |  01  |  02  \n\t\t\t    _________________________\t\t\t\t    __________________________\n" << std::endl;
	std::cout << "\t\t\t\t  " << static_cast<char>(grid[1][0]) << "  |  " << static_cast<char>(grid[1][1]) << "  |  " << static_cast<char>(grid[1][2]);
	std::cout << "\t\t\t\t\t\t  10  |  11  |  12  \n\t\t\t    _________________________\t\t\t\t    __________________________\n" << std::endl;
	std::cout << "\t\t\t\t  " << static_cast<char>(grid[2][0]) << "  |  " << static_cast<char>(grid[2][1]) << "  |  " << static_cast<char>(grid[2][2]);
	std::cout << "\t\t\t\t\t\t  20  |  21  |  22  " << std::endl;
	std::cout << "\t\t\t\t     |     |     \t\t\t\t\t      |      |      " << std::endl;


}

void gamerun::returnval() {//changes the value of the boxes to their original ones.

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grid[i][j] = who::empty;
	mainmenu();
}




void gamerun::mainmenu() {

	system("cls");

	std::cout << "\n\n\n\t\t\t\tCrosses and Knots! (V 1.6)\n\t\t\t\tBy Gokul Viswanath\n\n\n\n\t\t\t\tPLAY GAME (PRESS P)\n"
		"\t\t\t\tCHOOSE OPPONENT (PRESS C)";

	char v = _getch();


	if (v == 'p' || v == 'P') {

		if (player == 1)multigame();
		else if (player == 2)aigame();

	}
	else if (v == 'C' || v == 'c') {

		system("cls");


		std::cout << "\n\n\n\n\n\t\t\t\tCHOOSE OPPONENT"
			"\n\n\t\t\t\tHUMAN  (PRESS H)\t(DEFAULT)\t"; (player == 1) ? std::cout << "CURRENT" : std::cout << " ";
		std::cout << "\n\t\t\t\tPC     (PRESS A)\t\t\t"; (player == 2) ? std::cout << "CURRENT" : std::cout << " ";

		char w = _getch();

		if (w == 'H' || w == 'h')player = 1;
		else if (w == 'A' || w == 'a') {

			player = 2;
			std::cout << "\n\n\t\t\tWARNING- Currently in V1.6, AI levels are not offered. The level will always be High \n\t\t\t"
				"i.e you can only Draw or Lose.\n\t\t\t";
			system("pause");
		}
		mainmenu();
	}
	else mainmenu();
}



bool gamerun::HasWon(who x)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		// horizontal rows
		if (grid[i][0] == x && grid[i][1] == x && grid[i][2] == x)
			return true;

		// verticals
		if (grid[0][i] == x && grid[1][i] == x && grid[2][i] == x)
			return true;
	}

	// diagonals
	if (grid[0][0] == x && grid[1][1] == x && grid[2][2] == x)
		return true;

	if (grid[0][2] == x && grid[1][1] == x && grid[2][0] == x)
		return true;

	return false;
}



void gamerun::aigame() {

	unsigned int turn = 0;

	for (;;) {

		system("cls");
		mainscreen();

		// human move
		if (turn == 0)
		{
			getHumanMove();

			if (HasWon(who::human))
			{
				system("cls");
				mainscreen();
				std::cout << "\n\n\nYou win?! IMPOSSIBLE!!!";
				break;
			}
		}
		else
		{
			std::cout << "\nComputer Move: ";

			Move pcmove = minimax();
			std::cout << pcmove.x << pcmove.y << "\n";
			grid[pcmove.x][pcmove.y] = who::comp;

			if (HasWon(who::comp))
			{
				system("cls");
				mainscreen();
				std::cout << "\n\n\nNot suprisingly, I win.";
				break;
			}
		}

		if (isTie())
		{
			system("cls");
			mainscreen();
			std::cout << "\n\nIt's a draw. How dull."; //if nobody wins

			break;

		}
		turn ^= 1;
	}

	ending();

}


int gamerun::maxSearch(int level)
{
	if (HasWon(who::human)) {
		return 10;
	}
	else if (HasWon(who::comp)) {
		return -10;
	}
	else if (isTie()) {
		return 0;
	}

	int score = std::numeric_limits<int>::min();

	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (grid[i][j] == who::empty)
			{
				grid[i][j] = who::human;
				score = std::max(score, minSearch(level + 1) - level);
				grid[i][j] = who::empty;
			}
		}
	}

	return score;
}

int gamerun::minSearch(int level)
{
	if (HasWon(who::human)) {
		return 10;
	}
	else if (HasWon(who::comp)) {
		return -10;
	}
	else if (isTie()) {
		return 0;
	}

	int score = std::numeric_limits<int>::max();

	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (grid[i][j] == who::empty)
			{
				grid[i][j] = who::comp;
				score = std::min(score, maxSearch(level + 1) + level);
				grid[i][j] = who::empty;
			}
		}
	}

	return score;
}



gamerun::Move gamerun::minimax()
{
	int score = std::numeric_limits<int>::max();
	Move move;
	int level = 0;

	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (grid[i][j] == who::empty)
			{
				grid[i][j] = who::comp;

				int temp = maxSearch(level);

				if (temp < score)
				{
					score = temp;
					move.x = i;
					move.y = j;
				}
				grid[i][j] = who::empty;
			}
		}
	}

	return move;
}

void gamerun::getHumanMove()
{
	bool fail = true;
	unsigned int x = -1, y = -1;

	do
	{
		std::cout << "\n\t\tEnter your move in coordinate form[row, col]. ex: 02\n\n\t\tYour Move- ";


		char p;
		std::cin >> p;
		x = p - '0';
		std::cin >> p;
		y = p - '0';

		fail = grid[x][y] != who::empty;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



		if (grid[x][y] == who::human || grid[x][y] == who::comp) {

			std::cout << "This spot has been taken already!\n";
			system("pause");
			std::cin.clear();
			std::cin.sync();
			c -= 1;
			continue;

		}//if you select a place already taken.

		else {
			if (c % 2 == 0)grid[x][y] = who::human;//changes the values of the boxes as you enter X or O
			else grid[x][y] = who::comp;
		}//else

	} while (fail);
}


bool gamerun::isTie()
{
	for (unsigned int i = 0; i < 3; i++)
	{
		if (grid[i][0] == who::empty || grid[i][1] == who::empty || grid[i][2] == who::empty)
			return false;
	}
	return true;
}
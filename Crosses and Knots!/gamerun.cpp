#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include "gamerun.h"

char grid[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

gamerun::gamerun()
{

	multigame();
	//ctor
}


void gamerun::multigame() { //

	grno = p = y = x = res = 0;

	for (p = 0; p < 9; p++) {
		system("Cls");
		mainscreen();

		if (p % 2 == 0)std::cout << "\n\n\nEnter a grid number, Player 1 (X)- ";
		else std::cout << "\n\n\nEnter a grid number, Player 2 (O)- ";
		std::cin >> grno;


		switch (grno) {

		case 1: y = 0; x = 0; break;//these are coordinates for the boxes.
		case 2: y = 0; x = 1; break;
		case 3: y = 0; x = 2; break;
		case 4: y = 1; x = 0; break;
		case 5: y = 1; x = 1; break;
		case 6: y = 1; x = 2; break;
		case 7: y = 2; x = 0; break;
		case 8: y = 2; x = 1; break;
		case 9: y = 2; x = 2; break;
		default: {std::cout << "Wrong input!\n"; system("pause"); std::cin.clear(); std::cin.sync(); p -= 1; continue; }
		}//switch

		if (grid[y][x] == 'X' || grid[y][x] == 'O') {
			std::cout << "This spot has been taken already!\n"; system("pause"); std::cin.clear(); std::cin.sync(); p -= 1;  continue;
		}//if you select a place already taken.
		else {
			if (p % 2 == 0)grid[y][x] = 'X';//changes the values of the boxes as you enter X or O
			else grid[y][x] = 'O';

			if ((grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O') || (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O') || (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O')) { res = 2; break; }
			else if ((grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') || (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O') || (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O')) { res = 2; break; }
			else if ((grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') || (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')) { res = 2; break; }
			else if ((grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X') || (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X') || (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X')) { res = 1; break; }
			else if ((grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X') || (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X') || (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X')) { res = 1; break; }
			else if ((grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') || (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')) { res = 1; break; }
			//this decides the winner  of the game.


		}//else



	}//loop
	std::cout << "\n\n\n\nres= " << res;
	system("pause");
	if (res == 1) { system("cls"); mainscreen(); std::cout << "\n\n\nPLAYER 1 WINS!  Good Game!!"; ending(); }//shows who the winner is 
	else if (res == 2) { system("cls"); mainscreen(); std::cout << "\n\n\nPLAYER 2 WINS!  Good Game!!"; ending(); }

	else {
		system("cls");      //if its a draw
		mainscreen();
		std::cout << "\n\nIT'S A DRAW!   Good Game!"; ending();//if nobody wins
	}


}//game

void gamerun::ending() {

	std::cout << "\n\nDo you want to play more or exit? Enter 'M' or 'E' as per your choice- ";
	char choice;
	std::cin >> choice;
	if (choice == 'm' || choice == 'M') { system("cls");  returnval(); }
	else if (choice == 'e' || choice == 'E') { std::cout << "\n\nThank you for playing! Exiting...\n\n"; exit(0); }
}

void gamerun::mainscreen() {

	std::cout << "\n\t\t\t\t\t--CROSSES AND KNOTS--\n\t\t\t\t\tMADE BY GOKUL VISWANATH\n\n\t\t\t\tPLAYER 1: X\t\tPLAYER 2: O\n\n\t\t\t\t\t      |      |      \n\t\t\t\t\t   " << grid[0][0] << "  |   " << grid[0][1] << "  |   " << grid[0][2] << std::endl;
	std::cout << "\t\t\t\t\t____________________" << std::endl;
	std::cout << "\t\t\t\t\t      |      |      \n\t\t\t\t\t   " << grid[1][0] << "  |   " << grid[1][1] << "  |   " << grid[1][2] << std::endl;
	std::cout << "\t\t\t\t\t____________________" << std::endl;
	std::cout << "\t\t\t\t\t      |      |      \n\t\t\t\t\t   " << grid[2][0] << "  |   " << grid[2][1] << "  |   " << grid[2][2] << std::endl;


}

void gamerun::returnval() {//changes the value of the boxes to their original ones.
	int v = 49;//ASCII value of 01.
	for (int q = 0; q <= 2; q++) {

		for (int a = 0; a <= 2; a++) {

			grid[q][a] = v;
			v += 1;
		}


	}
	multigame();
}
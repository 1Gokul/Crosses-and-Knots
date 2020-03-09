#ifndef GAMERUN_H
#define GAMERUN_H


class gamerun
{


	enum class who
	{
		empty = '-',
		human = 'X',
		comp = 'O'
	};


	struct Move {

		int x;
		int y;
	};


	int c;
	int player;
	int score;

	who grid[3][3];
public:
	gamerun();
	void multigame();
	void ending();
	void mainscreen();
	bool isTie();
	void returnval();
	void aigame();
	bool HasWon(who x);
	void mainmenu();
	Move minimax();
	void getHumanMove();
	int maxSearch(int level);
	int minSearch(int level);
	int board[3][3];


};

#endif // GAMERUN_H

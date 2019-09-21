//Programmer: Tin Nguyen 
//aiFunctions.cpp
#include "gameHelper.h"
#include "aiFunctions.h"

int getMoves(int***& piles, int x, int y, int z)
{
	int moves = 0;
	//Base Case, when there are no more moves
	int t1 = x, t2 = y, t3 = z;
	if (x != 0 && y == 0 && z == 0) {
		piles[t1][t2][t3] = 0;
		return moves;
	}

	//Possible Move#1
	//Here we have to distinguish that z != 0 so a player cannot subtract with a 0 pile.
	t1 = x - z; t2 = y; t3 = z;
	sort(t1, t2, t3);
	if (z != 0) {
		if(piles[t1][t2][t3] == -2)
			piles[t1][t2][t3] = -1;
		moves++;
	}

	//Possible Move#2
	// Since they are sorted in descending order we don’t have to worry if ‘y’ will equal 0 because if it does then the base case would occur.
	t1 = x - y; t2 = y; t3 = z;
	sort(t1, t2, t3);
	if (piles[t1][t2][t3] == -2) {
		piles[t1][t2][t3] = -1;
		//For convenience we can set a game to losing ig it forms (x,0,0)
		if (t2 == 0) {
			piles[t1][t2][t3] = 0;
		}
	}
	moves++;


	//Possible Move#3
	//Here we have to distinguish that z != 0 so a player cannot subtract with a 0 pile.
	t1 = x; t2 = y - z; t3 = z;
	sort(t1, t2, t3);
	if (z != 0) {
		if(piles[t1][t2][t3] == -2)
			piles[t1][t2][t3] = -1;
		//For convenience we can set a game to losing ig it forms (x,0,0)
		if (t2 == 0) {
			piles[t1][t2][t3] = 0;
		}
		moves++;
	}
	
	return moves;
}

bool isWinner(int***& piles, int x, int y, int z) {
	int t1 = x,
		t2 = y,
		t3 = z;
	getMoves(piles, t1, t2, t3);

	//Base case if the move is already stored as winning
	if (piles[x][y][z] == 1)
		return true;

	//Base case if the move is already stored as losing
	if (piles[x][y][z] == 0)
		return false;

	// If one of the children game states is losing the current game state can be declared winning. If ALL of the children game states winning the current game state is declared losing.
	if (piles[x][y][z] == -1) {
		if (z != 0) {
			//Possible Move#1
			t1 = x - z; t2 = y, t3 = z;
			sort(t1, t2, t3);
			if (isWinner(piles, t1, t2, t3) == false) {
				piles[x][y][z] = 1;
				return true;
			}

			//Possible Move#2
			t1 = x;  t2 = y - z; t3 = z;
			sort(t1, t2, t3);
			if (isWinner(piles, t1, t2, t3) == false) {
				piles[x][y][z] = 1;
				return true;
			}
		}

		//Possible Move#3
		t1 = x - y; t2 = y; t3 = z;
		sort(t1, t2, t3);
		if (isWinner(piles, t1, t2, t3) == false) {
			piles[x][y][z] = 1;
			return true;
		}

		//All of the outcomes result in a win, thus the game state is determined Losing
		else {
			piles[x][y][z] = 0;
			return false;
		}
	}

}

void bestMove(int***& piles, int x, int y, int z, int &pileChoice1, int &pileChoice2) {
	//If give game state is losing let the other play go first
	if (isWinner(piles, x, y, z) == false) {
		pileChoice1 = 0;
		pileChoice2 = 0;
		return;
	}


	int t1 = x,	t2 = y,	t3 = z;
	if (isWinner(piles, x, y, z) == true) {
		if (z != 0) {
			//Possible Move#1
			t1 = x - z, t2 = y, t3 = z;
			sort(t1, t2, t3);
			if (isWinner(piles, t1, t2, t3) == false) {
				pileChoice1 = 1;
				pileChoice2 = 3;
				return;
			}

			//Possible Move#2
			t1 = x, t2 = y - z, t3 = z;
			sort(t1, t2, t3);
			if (isWinner(piles, t1, t2, t3) == false) {
				pileChoice1 = 2;
				pileChoice2 = 3;
				return;
			}
		}

		//Possible Move#3
		t1 = x - y, t2 = y, t3 = z;
		sort(t1, t2, t3);
		if (isWinner(piles, t1, t2, t3) == false) {
			pileChoice1 = 1;
			pileChoice2 = 2;
			return;
		}
	}
}
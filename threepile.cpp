//Programmer: Tin Nguyen 
//threepile.cpp
#include <iostream>
#include <stdio.h>
#include "gameHelper.h"
#include "aiFunctions.h"

using namespace std;

int main() {

	int pileChoice1 = 0; //Pile to subract from
	int pileChoice2 = 0; //Pile to subtract with

	int p1 = 0; //Pile #1
	int p2 = 0; //Pile #2
	int p3 = 0; //Pile #3

	cout << "Welcome to the Unbeatable AI Three-Pile Subtraction Game!" << endl
		<< "There are two players in the game, you and me (the AI)" << endl
		<< "You get to select the number of stones in each pile" << endl
		<< "But the catch is AI gets to choose who goes first!" << endl
		<< "******************************************************" << endl;
	cout << "Here are the rules: " << endl
		<< "1. Each move consists of removing one pile from another." << endl
		<< "2. A player may not remove more stones than the pile contains." << endl
		<< "3. A player cannot remove 0 stones. A pile of 0 is no longer usable." << endl
		<< "4. The player to make the last move wins" << endl
		<< "5.                      Have fun!" << endl
		<< "******************************************************" << endl;
	
	cout << endl << "Game Start!" << endl;
	cout << "Enter three integers separated by a SPACE to set the amount in each pile: " << std::endl;
	cin >> p1 >> p2 >> p3;

	// This is where the pile is made using a dyanmic 3D array structure
	sort(p1, p2, p3);

	int *** piles;

	piles = new int**[p1+1];
	for (int i = 0; i < p1+1; i++)
	{
		piles[i] = new int*[p2+1];
		for (int j = 0; j < p2+1; j++)
		{
			piles[i][j] = new int[p3+1];
		}
	}

	//Initializing all of the piles to Unused(-2)
	for (int i = 0; i < p1+1; i++)
	{
		for (int j = 0; j < p2+1; j++)
			for (int k = 0; k < p3+1; k++)
				piles[i][j][k] = -2;
	}

	//Setting the first move to Unknown(-1)
	piles[p1][p2][p3] = -1;

	bestMove(piles, p1, p2, p3, pileChoice1, pileChoice2);
	if (pileChoice1 == 0 && pileChoice2 == 0) {
		cout << "You go first " << endl;
	}

	else {
		cout << "I'll go first " << endl;
	}

	/* // <--If you want to see how the AI beats the player remove the commenting
	cout << endl << "*******TESTING********" << endl;
	cout << "0 = Losing, 1 = Winning, -1 = Unknown" << endl;
	
	cout << "Move1: p1 - p3  --> ";
	int t1 = p1, t2 = p2, t3 = p3;
	t1 = t1 - t3; t2 = p2; t3 = p3;
	sort(t1, t2, t3);
	cout << piles[t1][t2][t3] << endl;

	cout << "Move1: p1 - p2  --> ";
	t1 = p1, t2 = p2, t3 = p3;
	t1 = t1 - t2; t2 = p2; t3 = p3;
	sort(t1, t2, t3);
	cout << piles[t1][t2][t3] << endl;

	cout << "Move1: p2 - p3  --> ";
	t1 = p1, t2 = p2, t3 = p3;
	t1 = t1; t2 = p2-p3; t3 = p3;
	sort(t1, t2, t3);
	cout << piles[t1][t2][t3] << endl;

	cout << endl << "INPUT:" << p1 << "," << p2 << "," << p3 << endl;
	cout << "Possible Moves: " << getMoves(piles, p1, p2, p3) << endl;
	if (piles[p1][p2][p3] == 0)
		cout <<	"LOSING" << endl << endl;

	else cout << "WINNING" << endl;
	cout << "A game state is considered winning as long as ONE of the moves results in a loss" << endl;
	cout << "*******TESTING********" << endl << endl;
	/////////////////////////////////// TESTING
	//If you want to see how the AI beats the player remove the commenting up top */
	cout << "Starting Pile: " << p1 << ", " << p2 << ", " << p3 << endl;
	
	if (pileChoice1 != 0 && pileChoice2 != 0) {
		cout << endl << "AI's move:" << endl;
		makeMove(p1, p2, p3, pileChoice1, pileChoice2);
	}
	
	while (p2 != 0 || p3 != 0) {
		cout << endl << "Current Piles: " << p1 << ",  " << p2 << ",  " << p3 << endl;
		cout << "Enter the pile to subract from and the pile to subract with separated by a space." << endl;
		cin >> pileChoice1 >> pileChoice2;
		makeMove(p1, p2, p3, pileChoice1, pileChoice2);

		cout << "Current Piles: " << p1 << ",  " << p2 << ",  " << p3 << endl;
		cout <<endl << "AI's move:" << endl;
		bestMove(piles, p1, p2, p3, pileChoice1, pileChoice2);
		makeMove(p1, p2, p3, pileChoice1, pileChoice2);
	} 

	return 0;
}
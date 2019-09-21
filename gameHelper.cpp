//Programmer: Tin Nguyen 
//gameHelper.cpp
#include <iostream>
#include "gameHelper.h"
using namespace std;

void sort(int &x, int &y, int &z) {
	if (x<y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	if (x<z) {
		int tmp = x;
		x = z;
		z = tmp;
	}
	if (y<z) {
		int tmp = y;
		y = z;
		z = tmp;
	}
}

void makeMove(int &p1, int &p2, int &p3, int pileChoice1, int pileChoice2) {
	if (p3 == 0 && pileChoice2 ==3) {
		cout << "ERROR: Cannot subtract a pile from 0" << endl << endl;
		cout << "Current Piles: " << p1 << ",  " << p2 << ",  " << p3 << endl;
		cout << "Enter the pile to subract from and the pile to subract with separated by a space." << endl;
		cin >> pileChoice1 >> pileChoice2;
		makeMove(p1, p2, p3, pileChoice1, pileChoice2);
	}

	else if (pileChoice1 == pileChoice2) {
		cout << "ERROR: Cannot subtract a pile from itself" << endl << endl;
		cout << "Current Piles: " << p1 << ",  " << p2 << ",  " << p3 << endl;
		cout << "Enter the pile to subract from and the pile to subract with separated by a space." << endl;
		cin >> pileChoice1 >> pileChoice2;
		makeMove(p1, p2, p3, pileChoice1, pileChoice2);
	}

	else if (pileChoice1 > pileChoice2) {
		cout << "ERROR: You can only subtract smaller piles from larger piles" << endl << endl;
		cout << "Current Piles: " << p1 << ",  " << p2 << ",  " << p3 << endl;
		cout << "Enter the pile to subract from and the pile to subract with separated by a space." << endl;
		cin >> pileChoice1 >> pileChoice2;
		makeMove(p1, p2, p3, pileChoice1, pileChoice2);
	}

	else if (pileChoice1 == 1 && pileChoice2 == 3) {
		cout << p1 << " - " << p3 << endl;
		p1 = p1 - p3;
		sort(p1, p2, p3);
	}

	else if (pileChoice1 == 1 && pileChoice2 == 2) {
		cout << p1 << " - " << p2 << endl;
		p1 = p1 - p2;
		sort(p1, p2, p3);
	}

	else if (pileChoice1 == 2 && pileChoice2 == 3) {
		cout << p2 << " - " << p3 << endl;
		p2 = p2 - p3;
		sort(p1, p2, p3);
	}

	if (p2 == 0 & p3 == 0) {
		cout << "Current Piles: " << p1 << ",  " << p2 << ",  " << p3 << endl;
		cout << endl << "Gameover AI wins!" << endl;
	}
}
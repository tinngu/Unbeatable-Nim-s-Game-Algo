//Programmer: Tin Nguyen 
//aiFunctions.h
#ifndef AIFUNCTIONS_H
#define AIFUNCTIONS_H

//These are the functions used by the AI to make it unbeatable!
int getMoves(int***& piles, int x, int y, int z);
bool isWinner(int***& piles, int x, int y, int z);
void bestMove(int***& piles, int x, int y, int z, int &pileChoice1, int &pileChoice2);

#endif



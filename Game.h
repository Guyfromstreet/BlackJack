#pragma once
#include "Card.h"

void playGame(int& balance);
void bank(int& balance, int& debt, int& percent);
void repay(int amount, int& debt, int& percent, int& balance);
void addCard(Hand& hand, const Card& currentCard);

#pragma once
#include <string>
#include <vector>
struct Card {

	std::string suit;
	std::string rank;
	int value = 0;

};

struct Hand {
	std::string name;
	std::vector<Card> cards;
	int sumCard = 0;
	int aceCount = 0;

};
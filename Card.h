#pragma once
#include <string>

struct Card {

	std::string suit;
	std::string rank;
	int value = 0;

};

struct Hand {

	int sumCard = 0;
	int aceCount = 0;

};
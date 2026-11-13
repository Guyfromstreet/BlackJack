#include "Deck.h"
#include <string>
#include <random>
#include <algorithm>

//Создание колоды
void GenerateDeck(Card deck[]) {

	int deckIndex = 0;

	std::string suits[4]{ "Черви", "Буби", "Крести", "Пики" };
	std::string rank[13]{ "Двойка", "Тройка", "Четвёрка", "Пятёрка", "Шестёрка", "Семёрка", "Восьмёрка", "Девятка", "Десятка", "Валет", "Дама", "Король", "Туз" };
	int values[13]{ 2,3,4,5,6,7,8,9,10,10,10,10,11 };
	//Заполнение колоды
	for (int s = 0; s < 4; s++) {
		for (int r = 0; r < 13; r++) {
			deck[deckIndex].suit = suits[s];
			deck[deckIndex].rank = rank[r];
			deck[deckIndex].value = values[r];
			deckIndex++;
		}
	}
}

	//Перемешивание карт
	void ShuffleDeck(Card deck[]) {

		std::random_device seed;
		std::mt19937 rng(seed());
		std::shuffle(deck,deck + DECK_SIZE, rng);

	}
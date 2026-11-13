#include <iostream>
#include <chrono>
#include <thread>
#include "UI.h"
#include "Card.h"
#include "Deck.h"

void playGame(int& balance) {
	//Переменные
	int bet = 0;
	int NumCards = 0;
	int sumDealer = 0;
	int valDealer = 0;
	int valCard = 0;
	int sumCard = 0;
	int cardIndex = 0;
	int pickCard = 1; //1 - брать, 2 - пас
	int aceCount = 0;
	int aceCountDealer = 0;
	int win = 0;

	std::string mes[] = {
		"Вы проиграли",
		"Ничья",
		"Вы выиграли"

	};

	std::cout << "\n\n\n| Начало Игры |\n";
	Card deck[52];
	GenerateDeck(deck, 52);
	ShuffleDeck(deck, 52);
	Card currentCard = deck[cardIndex];

	//Ставка
	std::cout << "Ваш баланс: " << balance;
	while (bet == 0) {

		std::cout << "Введите свою ставку: ";
		std::cin >> bet;
		std::cout << "\nСтавка принята";
		if (std::cin.fail() || bet > balance || bet < 1) {
			errInput();
			bet = 0;
		}
	}

	//Раздача
	std::cout << "Раздача\n\n";

	//Выдача первых карт
	for (int i = 0; i < 2; i++) {
		//Игроку
		currentCard = deck[cardIndex];
		cardIndex++;
		std::cout << currentCard.rank << " " << currentCard.suit << "\n" << currentCard.value << "\n\n";
		valCard = currentCard.value;
		sumCard = sumCard + valCard;
		if (currentCard.rank == "Туз") {
			aceCount++;
		}
		while (aceCount > 0 && sumCard > 21) {
			sumCard = sumCard - 10;
			aceCount--;
		}

		//Дилеру
		currentCard = deck[cardIndex];
		cardIndex++;
		valDealer = currentCard.value;
		sumDealer = sumDealer + valDealer;
		if (currentCard.rank == "Туз") {
			aceCountDealer++;
		}
		while (aceCountDealer > 0 && sumDealer > 21) {
			sumDealer = sumDealer - 10;
			aceCountDealer--;
		}
		if (i == 1) {
			std::cout << "Карта Дилера: " << currentCard.rank << " " << currentCard.suit << "\n" << currentCard.value << "\n\n";
		}
	}

	while (pickCard != 2 && sumCard < 21) {
		std::cout << "Количество очков: " << sumCard << "\n";
		std::cout << "Взять ещё одну?\n 1. Да \n 2. Нет \n Ввод: ";
		std::cin >> pickCard;
		if (std::cin.fail() || pickCard < 1 || pickCard > 2) {
			errInput();
			std::cout << "\nВведите число от 1 до 2\n\n\n";
			pickCard = 0;

		}

		if (pickCard == 1) {
			std::cout << "\n---Получена карта---\n";
			currentCard = deck[cardIndex];
			std::cout << currentCard.rank << " " << currentCard.suit << "\n" << currentCard.value << "\n\n";
			valCard = currentCard.value;
			sumCard = sumCard + valCard;
			cardIndex++;
			NumCards++;
			if (currentCard.rank == "Туз") {
				aceCount++;
			}
			while (aceCount > 0 && sumCard > 21) {
				sumCard = sumCard - 10;
				aceCount--;
			}
		}

	}
	//Ход дилера
	while (sumDealer < 17 && sumCard <= 21) {

		currentCard = deck[cardIndex];
		valDealer = currentCard.value;
		sumDealer = sumDealer + valDealer;
		cardIndex++;
		if (currentCard.rank == "Туз") {
			aceCountDealer++;
		}
		while (aceCountDealer > 0 && sumDealer > 21) {
			sumDealer = sumDealer - 10;
			aceCountDealer--;
		}
	}

	std::cout << "═══════════════════════════\n\n";
	// Исходы
	int change = 0;   // на сколько изменится баланс: минус, ноль или плюс

	if (sumCard > 21) {
		std::cout << "У вас " << sumCard << " очков\nПеребор. Вы проиграли\n";
		change = -bet;
	}
	else if (sumDealer > 21) {
		std::cout << "У дилера перебор. Вы выиграли\n";
		change = bet;
	}
	else {
		int state = (sumCard > sumDealer) - (sumDealer > sumCard) + 1;
		change = (state - 1) * bet;
		std::cout << "Ваши очки: " << sumCard << ".\nОчки дилера: " << sumDealer << "\n";
		std::cout << mes[state] << "\n";
	}

	balance += change;
	std::cout << "Ваш баланс: " << balance << "\n";

	backToMenu();

}


void bank(int& balance, int& debt, int& percent) {
	int choice = 0;
	int takeDebt = 0;
	int repayment = 0;

	std::cout << "Добро пожаловать в банк\n";

	std::cout << "1. Взять кредит\n2. Отдать долг\n 3.Уйти\n";
	std::cin >> choice;
	switch (choice) {

		case 1: 

			std::cout << "Введите сумму кредит (100-10000): ";
			std::cin >> takeDebt;

			if (std::cin.fail() || takeDebt < 100 || takeDebt > 10000) {

				errInput();
				takeDebt = 0;
				break;
			}

			debt += takeDebt;
			balance += takeDebt;
			backToMenu();
			break;
		
		case 2: 

			std::cout << "К возврату " << debt + percent;
			std::cout << "Введите сумму погашения: ";
			std::cin >> repayment;

			if (std::cin.fail() || repayment < 1 || repayment > debt + percent || repayment > balance) {

				errInput();
				repayment = 0;
				break;
			}

			debt -= repayment;
			balance -= repayment;

			if (debt < 0) {

				percent += debt;
				debt = 0;

			}
			backToMenu();
			break;
		case 3:

			break;
		
		default:

			errInput();

	}

}
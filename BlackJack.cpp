#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Card.h"
#include "Deck.h"
#include "UI.h"
#include "Game.h"
#define NOMINMAX
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32


int main() {

	#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
	#endif

	//Переменные
	int choice = 0;
	int balance = 1000;
	int debt = 0;
	int percent = 0;
	Credits();
	do {
		//Меню игры
		std::cout << "\n\n\nДобро пожаловать в меню\n";
		std::cout << "\nВыберите действие:\n"
			"1. Начать игру\n"
			"2. Банк\n"
			"3. Правила\n"
			"4. О разработчиках\n"
			"5. Закрыть программу\n";
		std::cout << "Ввод ";
		std::cin >> choice;


			switch (choice) {

			case 1:
				//Начисление процентов
				percent += static_cast<int>(std::ceil(debt * 0.01));
				//Сама игра
				playGame(balance);

				break;

			case 2:
				bank(balance, debt, percent);
				break;

			case 3:

				showRules();
				break;

			case 4:

				showAbout();
				break;

			case 5:

				std::cout << "Завершение работы программы. Ожидайте...\n\n";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				return 0;

			default: {

				errInput();

			}
			}
	} while (choice != 5);

	return 0;
}

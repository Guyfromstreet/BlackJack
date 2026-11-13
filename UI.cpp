#include "UI.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <limits>

void errInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Ошибка ввода\nПовторите ввод ещё раз";
	std::string dummy;
	std::getline(std::cin, dummy);
}

void backToMenu() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "Для возвращения в меню нажмите Enter\n";
	std::cout << "Ожидание ввода...\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string dummy;
	std::getline(std::cin, dummy);

}

void showRules() {
	std::cout << "\n\n\n╔═══════════════════════════╗\n"
		"║          Правила          ║\n"
		"╚═══════════════════════════╝\n\n"
		"Цель игры - набрать 21 очко или приблизиться к этому значению."
		"Больше - перебор\n"
		"Значения карт:\n"
		"Карты с номиналом 2-10 - 2-10 очков соответственно\n"
		"Валет, Дама, Король - 10 очков\n"
		"Туз - 11 очков\n\n";
	backToMenu();

}

void showAbout() {
	std::cout << "\n\n\nВерсия: 0.01\n"
		"Разработчик:\n"
		"Poststudios\n"
		"При поддержке Guy_from_street prod.\n\n";
	backToMenu();

}

void Credits() {

	//Начальные титры
	std::cout << R"(
   ▄██████▄     ▄████████    ▄████████
  ███    ███   ███    ███   ███    ███
  ███    █▀    ███    █▀    ███    █▀ 
 ▄███         ▄███▄▄▄       ███       
▀▀███ ████▄  ▀▀███▀▀▀     ▀███████████
  ███    ███   ███                 ███
  ███    ███   ███           ▄█    ███
  ████████▀    ███         ▄████████▀ 
	)" << std::endl;

	std::cout << "При поддержке Guy_from_street prod.\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Разработано Poststudos\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Загрузка приложения...\n\n\n\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "╔═══════════════════════════╗\n"
		"║         BlackJack         ║\n"
		"╚═══════════════════════════╝\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));

}

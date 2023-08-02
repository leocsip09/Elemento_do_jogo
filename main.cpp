#include "menu.h"
#include <iostream>
#include "SFML/Graphics.hpp"

int main() {
	Menu* menu = new Menu();
	menu->run_menu();
	delete menu;
	menu = nullptr;
	return EXIT_SUCCESS;
}

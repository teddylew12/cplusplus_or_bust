//Theodore Lewitt
// ITP 165, Summer 2020
// Homework 6
//lewitt@usc.edu

#include <ctime>
#include <string>
#include <iostream>
#include <array>
#include "Hero.h"
int main() {
	//Prime random number generator
	std::srand(std::time(0));
	//Get warrior name
	std::cout << "Hi There! \nWhat's the name of your warrior?" << std::endl;
	std::string warriorName;
	//List of enemies
	std::array<std::string, 5> opponentNames = { "Big Bad Wolf","Slenderman","Overdue Assignment","Basilisk","Hydra" };
	Hero opponent;
	bool winner;

	std::cin >> warriorName;
	Hero yourHero = Hero(warriorName);
	bool running = true;
	//Start interaction loop
	while (running) {
		int choice;
		//Get User input
		std::cout << "Menu:\n1)Print Info\n2)Heal\n3)Fight\n4)Quit\nChoose: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			//Print hero info
			yourHero.print();
			break;
		case 2:
			//Heal hero
			yourHero.heal();
			break;
		case 3:
			//Fight
			opponent = Hero(opponentNames[rand() % 5]);
			//Check if hero can fight
			if (yourHero.getCurrentHealth()>0) {
				winner = yourHero.fight(opponent);
				//Interpret Winner
				if (winner) {
					std::cout << yourHero.getName() << " won!" << std::endl;
				}
				else {
					std::cout << opponent.getName() << " won!" << std::endl;
				}
			}
			else {
				std::cout << "You can't fight right now!" << std::endl;
			}
			
			break;
		case 4:
			running = false;
			std::cout << "Adios!" << std::endl;
			break;
		default:
			std::cout << "Invalid!";
			break;
		}

	}
	return 0;
}
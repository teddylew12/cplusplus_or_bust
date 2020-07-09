#include "Point.h"
#include <vector>
#include <iostream>
#include <string>
int main() {
	std::vector <Point> allPoints;
	bool running = true;
	while (running) {
		int option;
		double newX, newY;
		int point1, point2;
		std::cout << "Choose from the following menu\n1. Add a new point\n2. Print all points\n3. Calculate Distance\n0. Quit" << std::endl;
		std::cin >> option;
		switch (option)
		{
		case 0:
			running = false;
			std::cout << "Goodbye!" << std::endl;
			break;
		case 1:
			//Get new point values
			std::cout << "Enter x :";
			std::cin >> newX;
			std::cout << "Enter y :";
			std::cin >> newY;
			//Make new Point and add it to list
			allPoints.push_back(Point(newX, newY));
			break;
		case 2:
			//Make sure vector isnt empty
			if (allPoints.empty()) {
				std::cout << "No Points to print!" << std::endl;
			}
			else {
				//Print all vectors
				for (int i = 0; i < allPoints.size(); i++) {
					std::cout << "Point " << i+1 << ":" << allPoints[i].print() << std::endl;
				}
			}
			break;
		case 3:
			if (allPoints.size() < 2) {
				std::cout << "Not enough points!"<<std::endl;
			}
			else {
				bool invalidChoice = true;
				//Validate points
				while (invalidChoice) {
					std::cout << "You have " << allPoints.size() << " points!\nPick an number between 1 and " << allPoints.size() << ":";
					std::cin >> point1;
					std::cout << "Pick another number between 1 and " << allPoints.size() << ":";
					std::cin >> point2;
					if ((point1 <= allPoints.size()) && (point1 > 0)&&(point2 <= allPoints.size()) && (point2 > 0)) {
						std::cout << "The distance between" << allPoints[point1-1].print() << " and " << allPoints[point2-1].print() << " is " << allPoints[point1-1].calcDist(allPoints[point2-1]) << std::endl;
						invalidChoice = false;
					}
					else {
						std::cout << "Invalid!" << std::endl;
					}
				}
			}
			break;
		
		default:
			std::cout << "invalid!\n";
			break;
		}
	}
	
}

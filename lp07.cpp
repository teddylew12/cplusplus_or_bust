// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 7
// lewitt@usc.edu
#include <iostream>
#include <string>
#include <vector>
#include "Graduate.h"
#include "Student.h"
#include "Undergraduate.h"
int main() {
	std::vector <Student*> allStudents;
	char option;
	bool running = true;
	while (running) {
		std::cout << "Do you want to create a (U)ndergrad or an (G)rad student or (Q)uit?" << std::endl;
		std::cin >> option;
		if ((option == 'q' || option == 'Q')) {
			running = false;
			for (Student* stud : allStudents) {
				stud->print();
			}
		}
		else if ((option == 'u' || option == 'U')) {
			std::string newName, newID;
			int unitsComp, unitsRegistered;
			std::cout << "Enter name: ";
			std::cin >> newName;
			std::cout << "Enter ID: ";
			std::cin >> newID;
			std::cout << "Enter number of completed units: ";
			std::cin >> unitsComp;
			std::cout << "Enter number of registered units this semester: ";
			std::cin >> unitsRegistered;
			Undergraduate* uGrad = new Undergraduate(newName, newID, unitsComp, unitsRegistered);
			allStudents.push_back(uGrad);
		}
		else if ((option == 'g' || option == 'G')) {
			std::string newName, newID, thesisName;
			int unitsComp, unitsRegistered;
			std::cout << "Enter name: ";
			std::cin >> newName;
			std::cout << "Enter ID: ";
			std::cin >> newID;
			std::cout << "Enter number of completed units: ";
			std::cin >> unitsComp;
			std::cout << "Enter number of registered units this semester: ";
			std::cin >> unitsRegistered;
			std::cout << "Enter thesis title: ";
			std::cin >> thesisName;
			Graduate* uGrad = new Graduate(newName, newID, thesisName, unitsComp, unitsRegistered);
			allStudents.push_back(uGrad);
		}
		else {
			std::cout << "Invalid option" << std::endl;
		}
		
	}
	


	
}
// Theodore Lewitt
// ITP 165, Summer 2020
// Homework 04
// lewitt@usc.edu
#include <string>
#include <fstream>
#include <iostream>

void WriteInfo(std::string& outputFilename, std::string& firstName, std::string& lastName, std::string& employeeTitle, double employeePay, bool isExempt);
bool ReadInfo(std::string& inputFilename, std::string& firstName, std::string& lastName, std::string& employeeTitle, double& employeePay, bool& isExempt);

int main() {
	//Print Menu
	std::cout << "Choose from the following menu:" << std::endl;
	std::cout << "\t1. View / Edit Employee Information" << std::endl;
	std::cout << "\t0. Quit" << std::endl;
	bool running = true;
	int option;
	std::string fileName;
	//Start overall program loop
	while (running) {
		std::cout << "Choose:";
		std::cin >> option;
		if (option == 1) {
			std::cout << "Enter filename of employee :";
			std::cin >> fileName;
			double employeePay;
			std::string fName, lName, employeeTitle;
			bool exemption;
			if (ReadInfo(fileName, fName, lName, employeeTitle, employeePay, exemption)) {
				bool modifying = true;
				while (modifying) {
					int modifyChoice;
					std::cout << "Choose from the following menu :\n\t1. Change Name\n\t2. Change Title\n\t3. Change Pay\n\t4. Change Exemption\n\t5. View Info\n\t0. Quit\n";
					std::cout << "Choose:";
					std::cin >> modifyChoice;
					double tempPay;
					std::string tempExempt;
					switch (modifyChoice)
					{
					case 0:
						std::cout << "Saving information...\nReturning to main menu..." << std::endl;
						WriteInfo(fileName, fName, lName, employeeTitle, employeePay, exemption);
						modifying = false;
					case 1:
						std::cout << "Enter a new first name:";
						std::cin >> fName;
						std::cout << "\nEnter a new last name:";
						std::cin >> lName;
						break;
					case 2:
						std::cout << "Enter a new title:";
						std::cin >> employeeTitle;
						break;
					case 3:
						std::cout << "Enter a new pay:";
						std::cin >> tempPay;
						//Validate Pay
						if (tempPay > 0) {
							employeePay = tempPay;
						}
						else {
							std::cout << "Invalid pay!" << std::endl;
						}
						break;
					case 4:
						std::cout << "Enter a new exemption status:";
						std::cin >> tempExempt;
						if (tempExempt == "EXEMPT") {
							exemption = true;
						}
						else if (tempExempt == "NONEXEMPT") {
							exemption = false;
						}
						else {
							std::cout << "Invalid response!" << std::endl;
						}
					case 5:
						std::cout << fName << " " << lName << std::endl;
						std::cout << employeeTitle << std::endl;
						std::cout << "Monthly Pay: " << employeePay << std::endl;
						if (exemption) {
							std::cout << "EXEMPT" << std::endl;
						}
						else {
							std::cout << "NONEXEMPT" << std::endl;
						}
						
						break;

					default:
						std::cout << "Invalid Option" << std::endl;
						break;
					}
				}


			}
			else {
				std::cout << "File couldn't be opened!" << std::endl;
			}
		}
		else if (option == 0) {
			//End program if user inputs 0
			running = false;
			std::cout << "Goodbye!" << std::endl;
		}
		else {
			std::cout << "Invalid option" << std::endl;
		}

	}
}

void WriteInfo(std::string& outputFilename, std::string& firstName, std::string& lastName, std::string& employeeTitle, double employeePay, bool isExempt) {
	//Open Stream
	std::ofstream fStream(outputFilename);
	//Write info
	fStream << lastName << std::endl;
	fStream << firstName << std::endl;
	fStream << employeeTitle << std::endl;
	fStream << employeePay << std::endl;
	if (isExempt) {
		fStream << "EXEMPT" << std::endl;
	}
	else {
		fStream << "NONEXEMPT" << std::endl;
	}

}

bool ReadInfo(std::string& inputFilename, std::string& firstName, std::string& lastName, std::string& employeeTitle, double& employeePay, bool& isExempt) {
	std::ifstream fStream(inputFilename);
	if (fStream.is_open()) {
		// Continue looping as long as not at EOF! 
		fStream >> lastName;
		fStream >> firstName;
		fStream >> employeeTitle;
		fStream >> employeePay;
		std::string exempt;
		fStream >> exempt;
		if (exempt == "EXEMPT") {
			isExempt = true;
		}
		else {
			isExempt = false;
		}
		return true;
	}
	else {
		return false;
	}

}
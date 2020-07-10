#include "NormAttack.h"
#include <iostream>
#include <string>
NormAttack::NormAttack() {
	m_accuracy = rand() % 50 + 40;
	m_multiplier = 1.0;
}
double NormAttack::use() {
	int rando = rand() % 99 + 1;
	//Check if attack landed
	if (rando < m_accuracy) {
		std::cout << "The attack landed!" << std::endl;
		return m_multiplier;
	}
	else {
		std::cout << "The attack missed!" << std::endl;
		return 0;
	}
}
std::string NormAttack::type() {
	return "NORM";
}
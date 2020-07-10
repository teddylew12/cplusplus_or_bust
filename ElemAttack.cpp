#include "ElemAttack.h"
#include <iostream>
#include <string>
ElemAttack::ElemAttack() {
	m_accuracy = rand() % 99 + 1;
	//Get mupltiplier based on accuracy
	if (m_accuracy <= 10) {
		m_multiplier = 4.5;
	}
	else if (m_accuracy <= 20) {
		m_multiplier = 3.5;
		}
	else if (m_accuracy <= 40) {
		m_multiplier = 2.5;
	}
	else if (m_accuracy <= 60) {
		m_multiplier = 2.0;
	}
	else if (m_accuracy <= 80) {
		m_multiplier = 1.5;
	}
	else {
		m_multiplier = 1.3;
	}
}
double ElemAttack::use() {
	//Check if attack landed
	int rando = rand() % 99 + 1;
	if (rando < m_accuracy) {
		std::cout << "The attack landed!" << std::endl;
		return m_multiplier;
	}
	else {
		std::cout << "The attack missed!" << std::endl;
		return 0;
	}
}
std::string ElemAttack::type() {
	return "ELEM";
}
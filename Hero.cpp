#include "Hero.h"
#include "Attack.h"
#include "ElemAttack.h"
#include "NormAttack.h"
#include <string>
#include <iostream>
Hero::Hero() {
	m_maxVal = 100;
	m_name = "";
	m_currentHealth = 100;
	m_powerLevel = 10;
};
Hero::Hero(std::string& newName) {
	m_name = newName;
	m_currentHealth = 80 + rand() % 20;
	m_maxVal = m_currentHealth;
	m_powerLevel = 10 + rand() % 5;
}

void Hero::setName(std::string& newName) {
	m_name = newName;
}

void Hero::setMaxVal(int newMaxVal) {
	m_maxVal = newMaxVal;

}
void Hero::setCurrentHealth(int newCurrentHealth) {
	if (newCurrentHealth < 0) {
		m_currentHealth = 0;
	}
	else {
		m_currentHealth = newCurrentHealth;
	}
	
}
void Hero::setPowerLevel(int newPowerLevel) {
	m_powerLevel = newPowerLevel;
}
void Hero::heal() {
	int newVal;
	if (m_currentHealth == 0) {
		m_currentHealth = 10;
	}
	newVal = m_currentHealth * 1.1;
	if (newVal > m_maxVal) {
		setCurrentHealth(m_maxVal);
		std::cout << m_name<<" is fully healed!\n";
	}
	else {
		std::cout << "Current Health is now " << newVal << "!\n";
		setCurrentHealth(newVal);
	}
}
void Hero::print() {
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Power Level: " << m_powerLevel << std::endl;
	std::cout << "Current Health: " << m_currentHealth << std::endl;
	std::cout << "Max Health: " << m_maxVal << std::endl;
}
bool Hero::fight(Hero& opponent) {
	int ct = 0;
	int choice;
	//Loop while both fighters are alive
	while ((opponent.getCurrentHealth() > 0) && (m_currentHealth > 0)) {
		
		printAllAttacks();
		bool invalid = true;
		while (invalid) {
			std::cout << "Pick an attack! Choose a number between 1 and " << m_allAttacks.size() << std::endl;
			std::cin >> choice;
			if ((choice > 0) && (choice <= m_allAttacks.size())) {
				invalid = false;
			}
			else {
				std::cout << "Invalid option!" << std::endl;
			}
		}
		//Lower healths based on accuracy ad multplier
		Attack* currentAttack = m_allAttacks[choice-1];
		opponent.setCurrentHealth(opponent.getCurrentHealth() - (currentAttack->use() * m_powerLevel));
		Attack* opponentAttack = opponent.allAttacks()[rand() % opponent.allAttacks().size()];
		setCurrentHealth(m_currentHealth - opponentAttack->use() * opponent.getPowerLevel());
		ct++;
		std::cout << "Turn: " << ct << std::endl;
		std::cout << m_name << " Health: " << m_currentHealth << std::endl;
		std::cout << opponent.getName() << " Health: " << opponent.getCurrentHealth() << std::endl;
		std::cout << "__________________________________" << std::endl;
	}
	//Check whom won
	if (m_currentHealth == 0) {
		return false;
	}
	else {
		return true;
	}
}
std::string Hero::getName() {
	return m_name;
}
int Hero::getMaxVal() {
	return m_maxVal;
}
int Hero::getCurrentHealth() {
	return m_currentHealth;
}
int Hero::getPowerLevel() {
	return m_powerLevel;
}

void Hero::addEAttack() {
	ElemAttack* newattack = new ElemAttack();
	m_allAttacks.push_back(newattack);
}
void Hero::addNAttack() {
	NormAttack* newNormAttack = new NormAttack();
	m_allAttacks.push_back(newNormAttack);
}
void Hero::printAllAttacks() {
	for (Attack* attack : m_allAttacks) {
		std::cout << "Attack Type: " << attack->type() << std::endl;
		std::cout << "Accuracy: " << attack->accuracy() << std::endl;
		std::cout << "Multiplier: " << attack->multiplier() << std::endl;
		std::cout << "-----------------------" << std::endl;
	}
}
std::vector<Attack*>& Hero::allAttacks() {
	return m_allAttacks;
}
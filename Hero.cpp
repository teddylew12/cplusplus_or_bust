#include "Hero.h"
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
	while ((opponent.getCurrentHealth() > 0) && (m_currentHealth > 0)) {
		ct++;
		std::cout << "Turn: " << ct << std::endl;
		std::cout << m_name << " Health: " << m_currentHealth << std::endl;
		std::cout << opponent.getName() << " Health: " << opponent.getCurrentHealth() << std::endl;
		opponent.setCurrentHealth(opponent.getCurrentHealth() - m_powerLevel);
		setCurrentHealth(m_currentHealth-opponent.getPowerLevel());
	}
	if (m_currentHealth < 0) {
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
#pragma once
#include <string>
#include <vector>
#include "Attack.h"
#include "ElemAttack.h"
#include "NormAttack.h"
class Hero
{
public:
	Hero();
	Hero(std::string& name);

	void setName(std::string& newName);
	void setMaxVal(int newMacVal);
	void setCurrentHealth(int newCurrentHealth);
	void setPowerLevel(int newPowerLevel);

	std::string getName();
	int getMaxVal();
	int getCurrentHealth();
	int getPowerLevel();
	std::vector<Attack*>& allAttacks();

	void heal();
	void print();
	bool fight(Hero& opponent);

	void addEAttack();
	void addNAttack();
	void printAllAttacks();

private:
	std::string m_name;
	int m_maxVal;
	int m_currentHealth;
	int m_powerLevel;
	std::vector <Attack*> m_allAttacks;

};


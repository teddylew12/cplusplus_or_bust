#pragma once
#include <string>
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

	void heal();
	void print();
	bool fight(Hero& opponent);
private:
	std::string m_name;
	int m_maxVal;
	int m_currentHealth;
	int m_powerLevel;

};


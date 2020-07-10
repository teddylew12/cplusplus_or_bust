#pragma once
#include <string>
class Attack
{
public:
	int m_accuracy;
	double m_multiplier;
	//Pure virtual functions
	virtual double use() = 0;
	virtual std::string type() = 0;
	int accuracy();
	double multiplier();
};


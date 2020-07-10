#pragma once
#include "Attack.h"
#include <string>
class NormAttack : public Attack
{
public:
	NormAttack();
	double use();
	std::string type();

};


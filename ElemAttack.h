#pragma once
#include "Attack.h"
#include <string>
class ElemAttack : public Attack
{
public:
	ElemAttack();
	double use();
	std::string type();

	
};


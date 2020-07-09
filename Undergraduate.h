// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 7
// lewitt@usc.edu
#pragma once
#include <string>
#include "Student.h"
class Undergraduate: public Student
{
public:
	Undergraduate(std::string& name, std::string& ID, int numCompleted, int numRegistered);
	void print();
	double calcuateTuition();

private:
	double m_unitCost = 1500.00;
};


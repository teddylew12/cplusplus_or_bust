// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 7
// lewitt@usc.edu
#pragma once
#include <string>
#include "Student.h"
class Graduate: public Student
{
public:
	
	Graduate(std::string& name, std::string& ID, std::string& thesisTitle, int numCompleted, int numRegistered);
	void print();
	double calcuateTuition();
private:
	std::string m_thesis;
};


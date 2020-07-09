// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 7
// lewitt@usc.edu
#pragma once
#include <string>
class Student
{
public:
	Student(std::string& name, std::string& ID, int numCompleted, int numRegistered);
	virtual void print() = 0;
	virtual double calcuateTuition() = 0;
protected:
	std::string m_name, m_id;
	int m_unitsCompleted, m_unitsRegistered;
};


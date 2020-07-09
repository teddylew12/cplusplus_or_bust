// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 7
// lewitt@usc.edu
#include "Student.h"
#include <string>
Student::Student(std::string& name, std::string& ID, int numCompleted, int numRegistered){
	m_name = name;
	m_id = ID;
	m_unitsCompleted = numCompleted;
	m_unitsRegistered = numRegistered;
}
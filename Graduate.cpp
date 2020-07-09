// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 7
// lewitt@usc.edu
#include "Graduate.h"
#include "Student.h"
#include <string>
#include <iostream>
Graduate::Graduate(std::string& name, std::string& ID, std::string& thesisTitle, int numCompleted, int numRegistered) :
	Student(name, ID, numCompleted, numRegistered), m_thesis(thesisTitle) {}
void Graduate::print() {
	std::cout << "Student Name: " << m_name << std::endl;
	std::cout << "Student ID: " << m_id << std::endl;
	std::cout << "Number of Units Completed: " << m_unitsCompleted << std::endl;
	std::cout << "Number of Units Registered: " << m_unitsRegistered << std::endl;
	std::cout << "Total Tuition Cost: " << calcuateTuition() << std::endl;
	std::cout << "Graduate Thesis: " << m_thesis << std::endl;
	std::cout << "----------------------------------" << std::endl;
}
double Graduate::calcuateTuition() {
	return  1300.00 * m_unitsRegistered;
}
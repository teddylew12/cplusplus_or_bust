// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 7
// lewitt@usc.edu
#include "Undergraduate.h"
#include <string>
#include "Student.h"
#include <iostream>
void Undergraduate::print() {
	std::cout << "Student Name: " << m_name << std::endl;
	std::cout << "Student ID: " << m_id << std::endl;
	std::cout << "Number of Units Completed: " << m_unitsCompleted << std::endl;
	std::cout << "Number of Units Registered: " << m_unitsRegistered << std::endl;
	std::cout << "Total Tuition Cost: " << calcuateTuition() << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

Undergraduate::Undergraduate(std::string& name, std::string& ID, int numCompleted, int numRegistered):
	Student(name, ID, numCompleted, numRegistered) {}

double Undergraduate::calcuateTuition() {
	return  1300.00 * m_unitsRegistered;
}
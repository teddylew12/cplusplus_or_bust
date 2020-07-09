#pragma once
#include <string>
class Point
{
public:
	//Constructors
	Point();
	Point(double x, double y);
	//Getters
	double getX();
	double getY();
	//Setters
	void setX(double newX);
	void setY(double newY);
	//Member Functions
	std::string print();
	double calcDist(Point& secondPoint);
private:
	double mX, mY;
};


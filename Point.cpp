#include "Point.h"
#include <math.h>
#include <string>
Point::Point() {
	mX = 0.0;
	mY = 0.0;
}
Point::Point(double x, double y) {
	mX = x;
	mY = y;
}
//Getters
double Point::getX() {
	return mX;
}
double Point::getY() {
	return mY;
}
//Setters
void Point::setX(double newX) {
	mX = newX;
}
void Point::setY(double newY) {
	mY = newY;
}

double Point::calcDist(Point& secondPoint) {
	//Use Euclidena distance formula
	return sqrt(pow(mX - secondPoint.getX(), 2) + pow(mY - secondPoint.getY(), 2));
}

std::string Point::print() {
	std::string toReturn = "";
	 toReturn+="(" + std::to_string(mX) + " , " + std::to_string(mY) + ")";
	 return toReturn;
}

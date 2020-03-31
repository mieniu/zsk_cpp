/*! \file Punkt2.cpp
*
* \brief Implementacja metod klasy Punkt2
*
* \author Szymon Siemieniuk
* \date 2020.03.27
* \version 1.11
*/

#include "Geometry/Punkt2.h"
#include <cmath>
#include <iostream>

unsigned int Punkt2::how_many = 0;

Punkt2::Punkt2() {
	how_many++;
	std::cout << "Konstruktor domyœlny: (0; 0)" << std::endl;
}

Punkt2::Punkt2(std::initializer_list<double> list) {
	if (list.size() >= 2) {
		x = list.begin()[0];
		y = list.begin()[1];
	}
	else if (list.size() == 1) {
		x = list.begin()[0];
		y = 0;
	}
	else {
		x = 0;
		y = 0;
	}
	std::cout << "Konstrukcja za pomoc¹ listy: " << *this << std::endl;
	how_many++;
}

Punkt2::Punkt2(double _x, double _y) : 
	x{ _x }, 
	y{ _y } 
{
	how_many++;
	std::cout << "Konstruktor przez wspó³rzêdne punktów: " << *this << std::endl;
}

Punkt2::Punkt2(const Punkt2& p) :
	x{ p.x }, 
	y{ p.y } 
{
	how_many++;
	std::cout << "Konstruktor kopiuj¹cy: " << *this << std::endl;
}

Punkt2::Punkt2(Punkt2&& _p) : 
	x{ _p.x }, 
	y{ _p.y } 
{
	_p.x = 0;
	_p.y = 0;
	std::cout << "Konstruktor przenosz¹cy: " << *this << std::endl;
}

Punkt2::~Punkt2() {
	how_many--;
	std::cout << "Zniszczono Punkt2" << std::endl;
}

void Punkt2::setX(double _x) {
	x = _x;
}

double Punkt2::getX() const {
	return x;
}

void Punkt2::setY(double _y) {
	y = _y;
}

double Punkt2::getY() const {
	return y;
}

double Punkt2::getRadius() const{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Punkt2::getAngle() const{
	return atan2(y,x);
}

unsigned int Punkt2::getCounter() {
	return how_many;
}

double Punkt2::getDistance(Punkt2 _p) const {
	double x_square = pow((x - _p.x), 2);
	double y_square = pow((y - _p.y), 2);
	return sqrt(x_square + y_square);
}

Punkt2 Punkt2::operator+(const Punkt2& p) const {
	return { x + p.getX(), y + p.getY() };
}

Punkt2 Punkt2::operator-(const Punkt2& p) const {
	return Punkt2(x - p.getX(), y - p.getY());
}

double Punkt2::operator*(const Punkt2& p) const {
	return (x * p.x) + (y * p.y);
}

std::ostream& operator<<(std::ostream& os, const Punkt2& obj) {
	os << "(" << obj.x << "; " << obj.y << ")";
	return os;
}

Punkt2 Punkt2::operator=(const Punkt2& p) {
	if (&p != this) {
		x = p.x;
		y = p.y;
	}
	return *this;
}

Punkt2& Punkt2::operator=(Punkt2&& p) {
	x = p.x;
	y = p.y;
	std::cout << "Przenosz¹cy operator przypisania" << std::endl;
	return *this;
}
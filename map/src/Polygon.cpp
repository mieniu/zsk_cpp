/*! \file Polygon.cpp
*
* \brief Implementacja metod klasy Polygon
*
* \author Szymon Siemieniuk
* \date 2020.03.27
* \version 1.11
*/

#include "Geometry/Polygon.h"
#include <cmath>
#include <exception>

unsigned int Polygon::how_many = 0;

Polygon::Polygon() : 
	vertices{ nullptr }, 
	count{ 0 } 
{
	how_many++;
}

Polygon::Polygon(Punkt2* points, const unsigned int len) : 
	vertices{ new Punkt2[len] } 
{
	for (unsigned int i = 0; i < len; i++) {
		vertices[i] = points[i];
		count++;
	}
	how_many++;
}

Polygon::Polygon(const Polygon& _poly) : 
	vertices{ new Punkt2[_poly.count] } 
{
	for (unsigned int i = 0; i < _poly.count; i++) {
		vertices[i] =  _poly.vertices[i];
		count++;
	}
	how_many++;
}

Polygon::Polygon(std::initializer_list<Punkt2> list) : 
	count{ (unsigned int) list.size() }, 
	vertices{ new Punkt2[count] } 
{
	for (int i=0; i<(int)count; i++) {
		double x = list.begin()[i].getX();
		double y = list.begin()[i].getY();
		vertices[i].setX(x);
		vertices[i].setY(y);
	}
	how_many++;
}

Polygon::~Polygon() {
	delete[] vertices;
	how_many--;
	std::cout << "Zniszczono Polygon" << std::endl;
}

void Polygon::setVertices(Punkt2 * _vertices, unsigned int _count) {
	vertices = _vertices;
	count = _count;
}

void Polygon::changeVertex(unsigned int i, double x, double y) {
	if (i > count)
		throw std::out_of_range("Podano wartoœæ 'i' wiêksz¹ od wierzcho³ków wielok¹ta!");
	else {
		vertices[i - 1].setX(x);
		vertices[i - 1].setY(y);
	}
}

double Polygon::getCount() {
	return count;
}

double Polygon::getPerimeter() {
	double perimeter = 0;
	for (unsigned int i = 0; i < count - 1; i++) {
		perimeter += vertices[i].getDistance(vertices[i + 1]);
	}
	perimeter += vertices[count].getDistance(vertices[0]);
	return perimeter;
}

double Polygon::getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3) {
	Punkt2 a;
	a.setX(p2.getX() - p1.getX());
	a.setY(p2.getY() - p1.getY());
	Punkt2 b;
	b.setX(p3.getX() - p1.getX());
	b.setY(p3.getY() - p1.getY());

	return 0.5 * abs((a.getX() * b.getY() - a.getY() - b.getX()));
}

double Polygon::getConvexArea() {
	double area = 0;
	for (unsigned int i = 1; i <= count - 2; i++) {
		area += getTriangleArea(vertices[0], vertices[i], vertices[i + 1]);
	}
	return area;
}

double Polygon::getArea() {
	double sum1 = 0;
	for (unsigned int i = 0; i < count - 2; i++) {
		sum1 += (vertices[i].getX()*vertices[i + 1].getY() +  vertices[count-1].getX()*vertices[0].getY());
	}
	double sum2 = 0;
	for (unsigned int i = 0; i < count - 2; i++) {
		sum2 += (vertices[i+1].getX()*vertices[i].getY() - vertices[0].getX()*vertices[count-1].getY());
	}

	return 0.5 * abs(sum1 - sum2);
}

double Polygon::getCounter() {
	return how_many;
};

std::ostream& operator<<(std::ostream& os, const Polygon& p) {
	os << "\nWielok¹t: \n";
	for (unsigned int i = 0; i < p.count; i++) {
		os << "[" << (i + 1) << "] " << p.vertices[i] << "\n";
	}
	return os;
}

Punkt2 Polygon::operator[] (unsigned int i) const {
	return vertices[i];
}

Polygon Polygon::operator=(const Polygon& p) {
	if (&p != this) {
		delete[] vertices;
		count = p.count;
		vertices = new Punkt2[count];
		for (unsigned int i = 0; i < count; i++) {
			vertices[i] = Punkt2{ p.vertices[i] };
		}
		std::cout << "Gotowe!" << std::endl;
	}
	return *this;
}

Polygon& Polygon::operator=(Polygon&& p) {
	delete[] vertices;
	vertices = p.vertices;
	p.vertices = nullptr;
	count = p.count;
	std::cout << "Przenosz¹cy operator przypisania dla Polygon" << std::endl;
	return *this;
}
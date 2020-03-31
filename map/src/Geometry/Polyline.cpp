#include "Polyline.h"
#include <exception>

unsigned int Polyline::instancesCounter = 0;

Polyline::Polyline() :
	vertices{ nullptr },
	v_count{ 0 }
{
	instancesCounter++;
}

Polyline::Polyline(Punkt2* points, const unsigned int len) :
	vertices{ new Punkt2[len] }
{
	for (unsigned int i = 0; i < len; i++) {
		vertices[i] = points[i];
		v_count++;
	}
	instancesCounter++;
}

Polyline::Polyline(const Polyline& _poly) :
	vertices{ new Punkt2[_poly.v_count] }
{
	for (unsigned int i = 0; i < _poly.v_count; i++) {
		vertices[i] = _poly.vertices[i];
		v_count++;
	}
	instancesCounter++;
}

Polyline::Polyline(std::initializer_list<Punkt2> list) :
	v_count{ (unsigned int)list.size() },
	vertices{ new Punkt2[v_count] }
{
	for (int i = 0; i < (int)v_count; i++) {
		double x = list.begin()[i].getX();
		double y = list.begin()[i].getY();
		vertices[i].setX(x);
		vertices[i].setY(y);
	}
	instancesCounter++;
}

Polyline::~Polyline() {
	delete[] vertices;
	instancesCounter--;
	std::cout << "Zniszczono Polyline" << std::endl;
}

void Polyline::setVertices(Punkt2* _vertices, unsigned int _count) {
	vertices = _vertices;
	v_count= _count;
}

void Polyline::changeVertex(unsigned int i, double x, double y) {
	if (i > v_count)
		throw std::out_of_range("Podano wartoœæ 'i' wiêksz¹ od wierzcho³ków wielok¹ta!");
	else {
		vertices[i - 1].setX(x);
		vertices[i - 1].setY(y);
	}
}

unsigned int Polyline::getVerticesCount() {
	return v_count;
}

double Polyline::getPerimeter() {
	double perimeter = 0;
	for (unsigned int i = 0; i <v_count- 1; i++) {
		perimeter += vertices[i].getDistance(vertices[i + 1]);
	}
	return perimeter;
}

double Polyline::getInstancesCounter() {
	return instancesCounter;
};

std::ostream& operator<<(std::ostream& os, const Polyline& p) {
	os << "\nLinia ³amana: \n";
	for (unsigned int i = 0; i < p.v_count; i++) {
		os << p.vertices[i] << "->";
	}
	os << std::endl;
	return os;
}

Punkt2 Polyline::operator[] (unsigned int i) const {
	if (i > v_count - 1)
		throw std::out_of_range("Oczekiwano wartoœci mniejszej ni¿ " + v_count);
	return vertices[i];
}

Polyline Polyline::operator=(const Polyline& other) {
	if (&other != this) {
		delete[] vertices;
		v_count= other.v_count;
		vertices = new Punkt2[v_count];
		for (unsigned int i = 0; i < v_count; i++) {
			vertices[i] = Punkt2{ other.vertices[i] };
		}
		std::cout << "Gotowe!" << std::endl;
	}
	return *this;
}

Polyline& Polyline::operator=(Polyline&& other) {
	delete[] vertices;
	vertices = other.vertices;
	other.vertices = nullptr;
	v_count= other.v_count;
	std::cout << "Przenosz¹cy operator przypisania dla Polyline" << std::endl;
	return *this;
}
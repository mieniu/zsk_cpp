#include "Geometry/MapPolygon.h"

MapPolygon::MapPolygon() : Polygon(), borderWidth{ 0 } {}

MapPolygon::MapPolygon(Punkt2* _vertex, const unsigned int _len, RGBA& _fillColor, RGBA& _borderColor, unsigned int _borderWidth=1) : 
	Polygon(_vertex, _len), 
	borderWidth{ _borderWidth },
	borderColor{ new RGBA(_borderColor) },
	fillColor{ new RGBA(_fillColor) } {}

MapPolygon::MapPolygon(const MapPolygon& other) : 
	Polygon(other.vertices, other.count),
	borderWidth{ other.borderWidth },
	borderColor{ new RGBA(*(other.borderColor)) },
	fillColor{ new RGBA(*(other.fillColor)) } {}

MapPolygon::MapPolygon(MapPolygon&& other) : 
	Polygon(other.vertices, other.count), 
	borderWidth{ other.borderWidth },
	borderColor{ other.borderColor },
	fillColor{ other.fillColor } {}

MapPolygon::MapPolygon(std::initializer_list<Punkt2> vertex, std::initializer_list<RGBA> rgba, unsigned int _borderWidth=1) : 
	Polygon(vertex), 
	borderWidth{ _borderWidth } 
{
	if (rgba.size() >= 2) {
		fillColor = new RGBA(rgba.begin()[0]);
		borderColor = new RGBA(rgba.begin()[1]);
	}
	else if (rgba.size() == 1) {
		fillColor = new RGBA(rgba.begin()[0]);
	}
}

MapPolygon::~MapPolygon() {
	if (borderColor != nullptr)
		delete borderColor;
	if (fillColor != nullptr)
		delete fillColor;
	if (description != nullptr)
		delete description;
}

unsigned int MapPolygon::getBorderWidth() {
	return borderWidth;
}

RGBA MapPolygon::getBorderColor() {
	return *borderColor;
}

RGBA MapPolygon::getFillColor() {
	return *fillColor;
}

void MapPolygon::setBorderWidth(unsigned int& _borderWidth) {
	borderWidth = _borderWidth;
}

void MapPolygon::setBorderColor(RGBA& _borderColor) {
	if(borderColor != nullptr)
		delete[] borderColor;
	borderColor = new RGBA(_borderColor);
}

void MapPolygon::setFillColor(RGBA& _fillColor) {
	if (fillColor != nullptr)
		delete[] fillColor;
	borderColor = new RGBA(_fillColor);
}

void MapPolygon::setDescription(std::string& text) {
	if (description != nullptr) {
		delete description;
	}
	description = new std::string(text);
}

std::ostream& operator<<(std::ostream& os, const MapPolygon& poly) {
	os << "Wielok¹t: \n";
	for (unsigned int i = 0; i < poly.count; i++) {
		os << "- [" << (i + 1) << "] " << poly.vertices[i] << "\n";
	}
	os << "- Wype³nienie: " << poly.fillColor << "\n";
	os << "- Obramowanie: " << poly.borderColor << ", " << poly.borderWidth << "px\n";
	os << "- Opis: " << *(poly.description) << "\n";
	return os;
}
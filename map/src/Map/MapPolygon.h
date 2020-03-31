#pragma once
#include "Polygon.h"
#include "RGBA.h"
#include <ostream>

class MapPolygon : public Polygon {
	unsigned int borderWidth;
	RGBA* borderColor = nullptr;
	RGBA* fillColor = nullptr;
	friend std::ostream& operator<<(std::ostream& os, const MapPolygon& poly);
public:
	MapPolygon();
	MapPolygon(Punkt2* _vertex, const unsigned int _len, RGBA& _fillColor, RGBA& _borderColor, unsigned int _borderWidth);
	MapPolygon(const MapPolygon& other);
	MapPolygon(MapPolygon&& other);
	MapPolygon(std::initializer_list<Punkt2> _vertex, std::initializer_list<RGBA> _rgba, unsigned int _len);
	~MapPolygon();
	unsigned int getBorderWidth();
	RGBA getBorderColor();
	RGBA getFillColor();
	void setBorderWidth(unsigned int& _borderWidth);
	void setBorderColor(RGBA& _borderColor);
	void setFillColor(RGBA& _fillColor);
};
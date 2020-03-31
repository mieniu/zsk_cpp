#pragma once
#include "../Geometry/Polygon.h"
#include "../Geometry/RGBA.h"
#include <ostream>
#include <string>

class MapPolygon : public Polygon {
protected:
	unsigned int borderWidth;
	RGBA* borderColor = nullptr;
	RGBA* fillColor = nullptr;
	friend std::ostream& operator<<(std::ostream& os, MapPolygon& poly);
	std::string* description = nullptr;
public:
	MapPolygon();
	MapPolygon(Punkt2* _vertex, const unsigned int _len, RGBA& _fillColor, RGBA& _borderColor, std::string _description, unsigned int _borderWidth);
	MapPolygon(const MapPolygon& other);
	MapPolygon(MapPolygon&& other);
	MapPolygon(std::initializer_list<Punkt2> _vertex, std::initializer_list<RGBA> _rgba, std::string _description, unsigned int _borderWidth);
	MapPolygon(std::initializer_list<Punkt2> _vertex, std::initializer_list<RGBA> _rgba, unsigned int _borderWidth);
	~MapPolygon();
	unsigned int getBorderWidth();
	RGBA getBorderColor();
	RGBA getFillColor();
	std::string getDescription();
	void setBorderWidth(unsigned int& _borderWidth);
	void setBorderColor(RGBA& _borderColor);
	void setFillColor(RGBA& _fillColor);
	void setDescription(std::string& text);
};
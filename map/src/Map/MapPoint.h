#pragma once
#include "../Geometry/Punkt2.h"
#include "../Geometry/RGBA.h"
#include <initializer_list>

class MapPoint :
	public Punkt2
{
protected:
	unsigned int visRadius;
	RGBA* visColor;
	friend std::ostream& operator<<(std::ostream& os, const Punkt2& p);
public:
	MapPoint() = delete;
	MapPoint(Punkt2& p, const unsigned int visRadius, RGBA visColor);
	MapPoint(std::initializer_list<double> point, unsigned int visRadius, RGBA visColor);
	~MapPoint();
	void setVisRadius(unsigned int newRadius);
	void setVisColor(RGBA& newColor);
	const unsigned int getVisRadius();
	const RGBA getVisColor();
};


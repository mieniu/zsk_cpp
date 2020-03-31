#pragma once
#include "../Geometry/Punkt2.h"
#include "../Geometry/RGBA.h"

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
	void setVisRadius(unsigned int newRadius);
	void setVisColor(RGBA& newColor);
	const unsigned int getVisRadius();
	const RGBA getVisColor();
};


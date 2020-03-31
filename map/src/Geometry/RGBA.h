#pragma once
#include <iostream>
#include <initializer_list>

class RGBA
{
	typedef unsigned char uchar;
	uchar red;
	uchar green;
	uchar blue;
	uchar alpha;
	friend std::ostream& operator<<(std::ostream& os, const RGBA& rgba);
public:
	RGBA() = delete;
	RGBA(uchar& _r, uchar& _g, uchar& _b, uchar _a);
	RGBA(const RGBA& other);
	RGBA(RGBA&& other);
	RGBA(std::initializer_list<uchar> list);
	~RGBA();
	void setRed(uchar& _red);
	void setGreen(uchar& _green);
	void setBlue(uchar& _blue);
	void setAlpha(uchar& _alpha);
	uchar getRed();
	uchar getGreen();
	uchar getBlue();
	uchar getAlpha();
};
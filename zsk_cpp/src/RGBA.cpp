#include "Geometry/RGBA.h"

RGBA::RGBA(unsigned char& _r, unsigned char& _g,  unsigned char& _b, unsigned char _a = 255) : 
	red{ _r }, 
	green{ _g }, 
	blue{ _b },
	alpha{ _a } {}


RGBA::RGBA(const RGBA& other)
	: red{ other.red },
	green{ other.green },
	blue{ other.blue },
	alpha{ other.alpha } {}


RGBA::RGBA(RGBA&& other) :
	red{ other.red },
	green{ other.green },
	blue{ other.blue },
	alpha{ other.alpha }
{
	other.red = 0;
	other.green = 0;
	other.blue = 0;
	other.alpha = 0;
}


RGBA::RGBA(std::initializer_list<unsigned char> list) {
	size_t s = list.size();
	if (s == 4) {
		red = list.begin()[0];
		green = list.begin()[1];
		blue = list.begin()[2];
		alpha = list.begin()[3];
	}
	else if (s == 3) {
		red = list.begin()[0];
		green = list.begin()[1];
		blue = list.begin()[2];
	}
	else {
		throw "Oczekiwana lista wartoœci z trzema lub czteroma parametrami, podano " + s;
	}
}


RGBA::~RGBA() {
	std::cout << "Zniszczono RGBA" << std::endl;
}

void RGBA::setRed(unsigned char& _red) {
	red = _red;
}

void RGBA::setGreen(unsigned char& _green) {
	green = _green;
}

void RGBA::setBlue(unsigned char& _blue) {
	blue = _blue;
}

void RGBA::setAlpha(unsigned char& _alpha) {
	alpha = _alpha;
}

unsigned char RGBA::getRed() {
	return red;
}

unsigned char RGBA::getGreen() {
	return green;
}

unsigned char RGBA::getBlue() {
	return blue;
}

unsigned char RGBA::getAlpha() {
	return alpha;
}

std::ostream& operator<<(std::ostream& os, const RGBA& rgba) {
	os << "RGBA(" << static_cast<unsigned>(rgba.red) << "; " << static_cast<unsigned>(rgba.blue) << "; " << static_cast<unsigned>(rgba.green) << "; " << static_cast<unsigned>(rgba.alpha) << ")";
	return os;
}
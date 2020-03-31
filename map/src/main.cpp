/*! \file main.cpp
*
* \brief Test operatora przypisania i indeksowania; test klasy Polygon
*
* \author Szymon Siemieniuk
* \date 2020.03.27
* \version 1.11
*/

#include "Map/Map.h"
#include <iostream>

int main() {
	setlocale(LC_ALL,"");

	MapPolygon p{ {{2.0,-1},{3,-2},{1,1}}, {{250,0,0}}, 2 };

	return 0;
}
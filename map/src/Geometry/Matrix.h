/*! \file Matrix.h
*
* \brief Zawiera deklaracjê klasy Matrix
* Wykorzystuje klasê "Punkt2"
*
* \author Szymon Siemieniuk
* \date 2020.03.27
* \version 1.11
*/

#pragma once
#include "Punkt2.h"
#include <initializer_list>

class Matrix
{
	double** tab;
	int sizeX; /*!< wymiar poziomy tablicy tab */
	int sizeY; /*!< wymiar pionowy tablicy tab */

public:
	Matrix();
	~Matrix();
	Matrix(std::initializer_list<std::initializer_list<double>>);
	Matrix(const Matrix& m);
	Matrix& operator=(const Matrix& m);
	Matrix& operator=(Matrix&& m);
	void operator[](int x);
	double operator()(int x, int y);
};

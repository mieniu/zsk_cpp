/*! \file Matrix.cpp
*
* \brief Implementacja metod klasy Matrix
*
* \author Szymon Siemieniuk
* \date 2020.03.27
* \version 1.11
*/

#include "Matrix.h"
#include <iostream>
#include <exception>

Matrix::Matrix() : 
	tab{ nullptr }, 
	sizeX{ 0 }, 
	sizeY{ 0 } {}

Matrix::~Matrix() {
	for (int i = sizeX-1; i >= 0; i--) {
		delete[] tab[i];
	}
	delete[] tab;
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) : 
	sizeX{ (int)list.size() } 
{
	{
		int maximum = (int)(list.begin()[0]).size();
		for (int i = 1; i < sizeX; i++) {
			int comparable = (int)(list.begin()[i]).size();
			if (maximum < comparable) {
				maximum = comparable;
			}
		}
		sizeY = maximum;
	}

	tab = new double* [sizeX];
	for (int i = 0; i < sizeX; i++) {
		tab[i] = new double[sizeY];
		for (int j = 0; j < sizeY; j++) {
			if (j < int(list.begin()[i].size())) {
				tab[i][j] = (list.begin()[i]).begin()[j];
			}
			else {
				tab[i][j] = 0;
			}
		}
	}
}

Matrix::Matrix(const Matrix& m) : 
	sizeX{ m.sizeX }, 
	sizeY{ m.sizeY } 
{
	tab = new double*[sizeX];
	for (int x = 0; x < sizeX; x++) {
		tab[x] = new double[sizeY];
		for (int y = 0; y < sizeY; y++) {
			tab[x][y] = m.tab[x][y];
		}
	}
}

Matrix& Matrix::operator=(const Matrix& m) {
	if (&m != this) {
		tab = new double* [sizeX];
		for (int i = 0; i < sizeX; i++) {
			tab[i] = new double[sizeY];
			for (int j = 0; j < sizeY; j++) {
				tab[i][j] = m.tab[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix&& m) {
	tab = m.tab;
	m.tab = nullptr;

	return *this;
}

void Matrix::operator[](int x) {
	if (x < sizeX) {
		std::cout << "{ ";
		for (int i = 0; i < sizeY-1; i++) {
			std::cout << tab[x][i] << "; ";
		}
		std::cout << tab[x][sizeY-1] << " }\n";
	}
	else {
		throw std::out_of_range("Podano wartoœæ X spoza zakresu!");
	}
}

double Matrix::operator()(int x, int y) {
	if (x < (sizeX-1) && y < (sizeY-1)) {
		return tab[x][y];
	} 
	else if (x >= sizeX) {
		throw std::out_of_range("Podano wartoœæ X spoza zakresu!");
	}
	else {
		throw std::out_of_range("Podano wartoœæ Y spoza zakresu!");
	}
}
/*! \file Polygon.h
* \brief Zawiera deklaracj� klasy Polygon
* Dziedziczy po Polyline
*
* \author Szymon Siemieniuk
* \date 2020.03.27
* \version 1.11
*/
#pragma once
#include "Punkt2.h"
#include <vector>

class Polygon
{
private:
	static unsigned int instancesCounter; /*!< Licznik*/
	friend std::ostream& operator<<(std::ostream& os, const Polygon& p);

protected:
	unsigned int v_count = 0; /*!< Liczba wierzcho�k�w wielok�ta */
	Punkt2* vertices; /*!< Tablica wierzocho�k�w */
	/*!
	 * \brief Metoda licz�ca pole tr�jk�ta o trzech podanych punktach
	 * \param p1 Punkt 1
	 * \param p2 Punkt 2
	 * \param p3 Punkt 3
	 * \return Pole tr�jk�ta
	 * \sa getTriangleArea()
	 */
	double getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3);

public:
	/*!
	 * \brief Konstruktor domy�lny
	 * \sa Polygon()
	 */
	Polygon();

	/*!
	 * \brief Konstruktor z punktem
	 * \param vertex Wska�nik obiekt�w Punkt2 zawieraj�cy wierzcho�ki
	 * \sa Polygon()
	 */
	Polygon(Punkt2* vertex, const unsigned int len);

	/*!
	 * \brief Konstruktor kopiuj�cy
	 * \param _poly Obiekt typu Polygon
	 */
	Polygon(const Polygon& _poly);

	/*!
	 * \brief Konstruktor z list� inicjalizacyjn�
	 * \param list Lista warto�ci typu Punkt2
	 */
	Polygon(std::initializer_list<Punkt2> list);

	/*!
	 * \brief Destruktor klasy Polygon
	 * \sa ~Polygon()
	 */
	~Polygon();

	/*!
	 * \brief Metoda konstruuj�ca tablic� wierzcho�k�w
	 * \param _vertices  argument typu Punkt*  przekazuj�cy tablic� wierzcho�k�w wielok�ta
	 * \param _v_count argument typu  unsigned int przekazuj�cy ilo�� wierzcho�k�w.
	 * \sa setVertices()
	 */
	void setVertices(Punkt2* _vertices, unsigned int _v_count);

	/*!
	 * \brief Metoda zmieniaj�ca wsp�lrz�dne i-tego wierzcho�ka.
	 * \param i argument typu int  przekazuj�cy numer wiercho�ka do zmiany
	 * \param x argument typu double przekazuj�cy now� warto�� do wsp�rz�dnej x.
	 * \param y argument typu double przekazuj�cy now� warto�� do wsp�rz�dnej y.
	 * \sa changeVertex()
	 */
	void changeVertex(unsigned int i, double x, double y);

	/*!
	 * \brief Metoda zwracaj�ca liczb� wierzcho�k�w.
	 * \return Liczba wierzcho�k�w
	 * \sa getVerticesCount()
	 */
	unsigned int getVerticesCount();

	/*!
	 * \brief Metoda obliczaj�ca obw�d wielok�ta
	 * \return Obw�d wielok�ta
	 * \sa getPerimeter()
	 */
	double getPerimeter();

	/*!
	 * \brief Metoda licz�ca pole wielok�ta wypuk�ego
	 * \return Pole wielok�ta
	 * \sa getConvexArea()
	 */
	double getConvexArea();

	/*!
	 * \brief Metoda licz�ca pole dowolnego wielok�ta
	 * \return Pole wielok�ta
	 * \sa getArea()
	 */
	double getArea();

	/*!
	 * \brief Metoda zwracaj�ca stan licznika. Nie wywo�ujemy jej na obiekcie
	 * \return Stan licznika
	 * \sa getInstancesCounter()
	 */
	unsigned int getInstancesCounter();

	Polygon operator=(const Polygon& polygon);
	Polygon& operator=(Polygon&& _p);
	Punkt2 operator[](unsigned int i) const;
};
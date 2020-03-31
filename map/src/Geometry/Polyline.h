/*! \file Polyline.h
*
* \brief Zawiera deklaracj� klasy Polyline
* Wykorzystuje klas� "Punkt2.h"
*
* \author Szymon Siemieniuk
* \date 2020.03.31
* \version 1.11
*/
#pragma once
#include "Punkt2.h"

class Polyline
{
private:
	static unsigned int how_many; /*!< Licznik*/
	friend std::ostream& operator<<(std::ostream& os, const Polygon& p);
protected:
	unsigned int count = 0; /*!< Liczba wierzcho�k�w wielok�ta */

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
	Polyline();

	/*!
	 * \brief Konstruktor z punktem
	 * \param vertex Wska�nik obiekt�w Punkt2 zawieraj�cy wierzcho�ki
	 * \sa Polygon()
	 */
	Polyline(Punkt2* vertex, const unsigned int len);

	/*!
	 * \brief Konstruktor kopiuj�cy
	 * \param _poly Obiekt typu Polygon
	 */
	Polyline(const Polyline& _poly);

	/*!
	 * \brief Konstruktor z list� inicjalizacyjn�
	 * \param list Lista warto�ci typu Punkt2
	 */
	Polyline(std::initializer_list<Punkt2> list);

	/*!
	 * \brief Destruktor klasy Polygon
	 * \sa ~Polygon()
	 */
	~Polyline();

	/*!
	 * \brief Metoda konstruuj�ca tablic� wierzcho�k�w
	 * \param _vertices  argument typu Punkt*  przekazuj�cy tablic� wierzcho�k�w wielok�ta
	 * \param _count argument typu  unsigned int przekazuj�cy ilo�� wierzcho�k�w.
	 * \sa changeVertex()
	 */
	void setVertices(Punkt2* _vertices, unsigned int _count);

	/*!
	 * \brief Metoda zmieniaj�ca wsp�lrz�dne i-tego wierzcho�ka.
	 * \param i argument typu int  przekazuj�cy numer wiercho�ka do zmiany
	 * \param x argument typu double przekazuj�cy now� warto�� do wsp�rz�dnej x.
	 * \param y argument typu double przekazuj�cy now� warto�� do wsp�rz�dnej y.
	 * \sa setVertices()
	 */
	void changeVertex(unsigned int i, double x, double y);

	/*!
	 * \brief Metoda zwracaj�ca liczb� wierzcho�k�w.
	 * \return Liczba wierzcho�k�w
	 * \sa getCount()
	 */
	double getCount();

	/*!
	 * \brief Metoda obliczaj�ca obw�d wielok�ta
	 * \return Obw�d wielok�ta
	 * \sa getPerimeter()
	 */
	double getPerimeter();

	/*!
	 * \brief Metoda zwracaj�ca stan licznika. Nie wywo�ujemy jej na obiekcie
	 * \return Stan licznika
	 * \sa getCounter()
	 */
	static double getCounter();

	Polyline operator=(const Polyline& polygon);
	Polyline& operator=(Polyline&& _p);
	Punkt2 operator[](unsigned int i) const;
};
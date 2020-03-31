/*! \file Polygon.h
* \brief Zawiera deklaracjê klasy Polygon
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
	unsigned int v_count = 0; /*!< Liczba wierzcho³ków wielok¹ta */
	Punkt2* vertices; /*!< Tablica wierzocho³ków */
	/*!
	 * \brief Metoda licz¹ca pole trójk¹ta o trzech podanych punktach
	 * \param p1 Punkt 1
	 * \param p2 Punkt 2
	 * \param p3 Punkt 3
	 * \return Pole trójk¹ta
	 * \sa getTriangleArea()
	 */
	double getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3);

public:
	/*!
	 * \brief Konstruktor domyœlny
	 * \sa Polygon()
	 */
	Polygon();

	/*!
	 * \brief Konstruktor z punktem
	 * \param vertex WskaŸnik obiektów Punkt2 zawieraj¹cy wierzcho³ki
	 * \sa Polygon()
	 */
	Polygon(Punkt2* vertex, const unsigned int len);

	/*!
	 * \brief Konstruktor kopiuj¹cy
	 * \param _poly Obiekt typu Polygon
	 */
	Polygon(const Polygon& _poly);

	/*!
	 * \brief Konstruktor z list¹ inicjalizacyjn¹
	 * \param list Lista wartoœci typu Punkt2
	 */
	Polygon(std::initializer_list<Punkt2> list);

	/*!
	 * \brief Destruktor klasy Polygon
	 * \sa ~Polygon()
	 */
	~Polygon();

	/*!
	 * \brief Metoda konstruuj¹ca tablicê wierzcho³ków
	 * \param _vertices  argument typu Punkt*  przekazuj¹cy tablicê wierzcho³ków wielok¹ta
	 * \param _v_count argument typu  unsigned int przekazuj¹cy iloœæ wierzcho³ków.
	 * \sa setVertices()
	 */
	void setVertices(Punkt2* _vertices, unsigned int _v_count);

	/*!
	 * \brief Metoda zmieniaj¹ca wspólrzêdne i-tego wierzcho³ka.
	 * \param i argument typu int  przekazuj¹cy numer wiercho³ka do zmiany
	 * \param x argument typu double przekazuj¹cy now¹ wartoœæ do wspó³rzêdnej x.
	 * \param y argument typu double przekazuj¹cy now¹ wartoœæ do wspó³rzêdnej y.
	 * \sa changeVertex()
	 */
	void changeVertex(unsigned int i, double x, double y);

	/*!
	 * \brief Metoda zwracaj¹ca liczbê wierzcho³ków.
	 * \return Liczba wierzcho³ków
	 * \sa getVerticesCount()
	 */
	unsigned int getVerticesCount();

	/*!
	 * \brief Metoda obliczaj¹ca obwód wielok¹ta
	 * \return Obwód wielok¹ta
	 * \sa getPerimeter()
	 */
	double getPerimeter();

	/*!
	 * \brief Metoda licz¹ca pole wielok¹ta wypuk³ego
	 * \return Pole wielok¹ta
	 * \sa getConvexArea()
	 */
	double getConvexArea();

	/*!
	 * \brief Metoda licz¹ca pole dowolnego wielok¹ta
	 * \return Pole wielok¹ta
	 * \sa getArea()
	 */
	double getArea();

	/*!
	 * \brief Metoda zwracaj¹ca stan licznika. Nie wywo³ujemy jej na obiekcie
	 * \return Stan licznika
	 * \sa getInstancesCounter()
	 */
	unsigned int getInstancesCounter();

	Polygon operator=(const Polygon& polygon);
	Polygon& operator=(Polygon&& _p);
	Punkt2 operator[](unsigned int i) const;
};
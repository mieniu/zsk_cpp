/*! \file Polyline.h
*
* \brief Zawiera deklaracjê klasy Polyline
* Wykorzystuje klasê "Punkt2.h"
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
	static unsigned int instancesCounter; /*!< Licznik*/
	unsigned int v_count = 0; /*!< Liczba wierzcho³ków wielok¹ta */
	Punkt2* vertices; /*!< Tablica wierzocho³ków */
	friend std::ostream& operator<<(std::ostream& os, const Polyline& p);

public:
	/*!
	 * \brief Konstruktor domyœlny
	 * \sa Polyline()
	 */
	Polyline();

	/*!
	 * \brief Konstruktor z punktem
	 * \param vertex WskaŸnik obiektów Punkt2 zawieraj¹cy wierzcho³ki
	 * \param len D³ugoœæ tablicy
	 * \sa Polyline()
	 */
	Polyline(Punkt2* vertex, const unsigned int len);

	/*!
	 * \brief Konstruktor kopiuj¹cy
	 * \param _poly Obiekt typu Polyline
	 */
	Polyline(const Polyline& _poly);

	/*!
	 * \brief Konstruktor z list¹ inicjalizacyjn¹
	 * \param list Lista wartoœci typu Punkt2
	 */
	Polyline(std::initializer_list<Punkt2> list);

	/*!
	 * \brief Destruktor klasy Polyline
	 * \sa ~Polyline()
	 */
	~Polyline();

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
	 * \brief Metoda zwracaj¹ca stan licznika. Nie wywo³ujemy jej na obiekcie
	 * \return Stan licznika
	 * \sa getCounter()
	 */
	static double getInstancesCounter();

	Polyline operator=(const Polyline& Polyline);
	Polyline& operator=(Polyline&& _p);
	Punkt2 operator[](unsigned int i) const;
};
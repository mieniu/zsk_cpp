/*! \file Punkt2.h
*
* \brief Zawiera deklaracjê klasy Punkt2
* Plik zawiera deklaracjê klasy Punkt2.h.
* Wspó³rzêdne punktu s¹ podawane w uk³adzie kartezjañskim.
* Klasa zawiera kilka metod sk³adowych
*
* \author Szymon Siemieniuk
* \date 2020.03.27
* \version 1.11
*/
#pragma once
#include <iostream>
#include <initializer_list>

class Punkt2
{
	static unsigned int how_many; /*!< Licznik*/
	double x{ 0.0 }; /*!< Wspó³rzêdna x*/
	double y{ 0.0 }; /*!< Wspó³rzêdna y*/
	friend std::ostream& operator<<(std::ostream& os, const Punkt2& obj); /*!< Prze³adowanie operatora << dla obiektu klasy ostream*/

public:
	/*!
	 * \brief Konstruktor domyœlny
	 * \sa Punkt2()
	 */
	Punkt2();

	/*!
	 * \brief Konstruktor z argumentami x,y
	 * \param _x,_y Wspó³rzêdne kartezjañskie kolejno: odciêta, rzêdna
	 * \sa Punkt2(double _x, double _y)
	 */
	Punkt2(double _x, double _y);

	/*!
	 * \brief Konstruktor kopiuj¹cy
	 * \sa Punkt2(const Punkt2& p)
	 */
	Punkt2(const Punkt2& p);

	/*!
	 * \brief Konstruktor z list¹ inicjalizacyjn¹
	 * \sa Punkt2(std::initializer_list<double> list);
	 */
	Punkt2(std::initializer_list<double> list);

	/*!
	 * \brief konstruktor przenosz¹cy
	 * \sa Punkt2(Punkt2&& p)
	 */
	Punkt2(Punkt2&& _p);

	/*!
	 * \brief Destruktor klasy Punkt2
	 * \sa ~Punkt2()
	 */
	~Punkt2();

	/*!
	 * \brief Ustawia odciêt¹ (wspó³rzêdn¹ X)
	 * \param _x Nowa wartoœæ
	 * \sa setX()
	 */
	void setX(double _x);

	/*!
	 * \brief Ustawia rzêdn¹ (wspó³rzêdn¹ Y)
	 * \param _y Nowa wartoœæ
	 * \sa setY()
	 */
	void setY(double _y);

	/*!
	 * \brief Zwraca odciêt¹ (wspó³rzêdn¹ X)
	 * \return Wartoœæ typu double
	 * \sa getX()
	 */
	double getX() const;

	/*!
	 * \brief Zwraca rzêdn¹ (wspó³rzêdn¹ Y)
	 * \return Wartoœæ typu double
	 * \sa getY()
	 */
	double getY() const;

	/*!
	 * \brief Zwraca wartoœæ licznika
	 * \return Wartoœæ typu int
	 * \sa getCounter()
	 */
	static unsigned int getCounter();

	/*!
	 * \brief Zwraca promieñ wodz¹cy
	 * \return Wartoœæ typu double
	 */
	double getRadius() const;

	/*!
	 * \brief Zwraca amplitudê punktu
	 * \return Wartoœæ typu double
	 */
	double getAngle() const;


	/*!
	 * \brief odleg³oœæ punktu od punktu _p
	 * \param _p Obiekt klasy punkt 2
	 * \return Odleg³oœæ wyra¿ona przez typ double
	 * \sa getDistance()
	 */
	double getDistance(Punkt2 _p) const;
	Punkt2 operator+(const Punkt2& p) const;
	Punkt2 operator-(const Punkt2& p) const;
	double operator*(const Punkt2& p) const;
	Punkt2 operator=(const Punkt2& p);
	Punkt2& operator=(Punkt2&& p);
};
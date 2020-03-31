/*! \file Punkt2.h
*
* \brief Zawiera deklaracj� klasy Punkt2
* Plik zawiera deklaracj� klasy Punkt2.h.
* Wsp�rz�dne punktu s� podawane w uk�adzie kartezja�skim.
* Klasa zawiera kilka metod sk�adowych
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
	double x{ 0.0 }; /*!< Wsp�rz�dna x*/
	double y{ 0.0 }; /*!< Wsp�rz�dna y*/
	friend std::ostream& operator<<(std::ostream& os, const Punkt2& obj); /*!< Prze�adowanie operatora << dla obiektu klasy ostream*/

public:
	/*!
	 * \brief Konstruktor domy�lny
	 * \sa Punkt2()
	 */
	Punkt2();

	/*!
	 * \brief Konstruktor z argumentami x,y
	 * \param _x,_y Wsp�rz�dne kartezja�skie kolejno: odci�ta, rz�dna
	 * \sa Punkt2(double _x, double _y)
	 */
	Punkt2(double _x, double _y);

	/*!
	 * \brief Konstruktor kopiuj�cy
	 * \sa Punkt2(const Punkt2& p)
	 */
	Punkt2(const Punkt2& p);

	/*!
	 * \brief Konstruktor z list� inicjalizacyjn�
	 * \sa Punkt2(std::initializer_list<double> list);
	 */
	Punkt2(std::initializer_list<double> list);

	/*!
	 * \brief konstruktor przenosz�cy
	 * \sa Punkt2(Punkt2&& p)
	 */
	Punkt2(Punkt2&& _p);

	/*!
	 * \brief Destruktor klasy Punkt2
	 * \sa ~Punkt2()
	 */
	~Punkt2();

	/*!
	 * \brief Ustawia odci�t� (wsp�rz�dn� X)
	 * \param _x Nowa warto��
	 * \sa setX()
	 */
	void setX(double _x);

	/*!
	 * \brief Ustawia rz�dn� (wsp�rz�dn� Y)
	 * \param _y Nowa warto��
	 * \sa setY()
	 */
	void setY(double _y);

	/*!
	 * \brief Zwraca odci�t� (wsp�rz�dn� X)
	 * \return Warto�� typu double
	 * \sa getX()
	 */
	double getX() const;

	/*!
	 * \brief Zwraca rz�dn� (wsp�rz�dn� Y)
	 * \return Warto�� typu double
	 * \sa getY()
	 */
	double getY() const;

	/*!
	 * \brief Zwraca warto�� licznika
	 * \return Warto�� typu int
	 * \sa getCounter()
	 */
	static unsigned int getCounter();

	/*!
	 * \brief Zwraca promie� wodz�cy
	 * \return Warto�� typu double
	 */
	double getRadius() const;

	/*!
	 * \brief Zwraca amplitud� punktu
	 * \return Warto�� typu double
	 */
	double getAngle() const;


	/*!
	 * \brief odleg�o�� punktu od punktu _p
	 * \param _p Obiekt klasy punkt 2
	 * \return Odleg�o�� wyra�ona przez typ double
	 * \sa getDistance()
	 */
	double getDistance(Punkt2 _p) const;
	Punkt2 operator+(const Punkt2& p) const;
	Punkt2 operator-(const Punkt2& p) const;
	double operator*(const Punkt2& p) const;
	Punkt2 operator=(const Punkt2& p);
	Punkt2& operator=(Punkt2&& p);
};
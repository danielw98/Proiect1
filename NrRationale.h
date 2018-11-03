#pragma once
#include <string>
using namespace std;
class Rational
{

public:


	/// constructori
	Rational();
	Rational(int, int);
	Rational(double);
	Rational(int);

	/// setteri si getteri

	void setValue(double);
	double getValue();
	void setNumerator(int);
	int getNumerator();
	void setDenominator(int);
	int getDenominator();

	/// supraincarcarea operatorilor aritmetici binari pt (Rational, Rational)
	friend Rational &operator+(const Rational&, const Rational&);
	friend Rational &operator-(const Rational&, const Rational&);
	friend Rational &operator*(const Rational&, const Rational&);
	friend Rational &operator/(const Rational&, const Rational&);

    /// supraincarcarea operatorilor aritmetici binari pt (double, Rational)
	friend Rational &operator+(double, const Rational&);
	friend Rational &operator-(double, const Rational&);
	friend Rational &operator*(double, const Rational&);
	friend Rational &operator/(double, const Rational&);

    /// supraincarcarea operatorilor aritmetici binari pt (Rational, int)
	friend Rational &operator+(const Rational&, int);
	friend Rational &operator-(const Rational&, int);
	friend Rational &operator*(const Rational&, int);
	friend Rational &operator/(const Rational&, int);

    /// supraincarcarea operatorilor aritmetici compusi pt (Rational, Rational)
	friend Rational &operator+=(Rational&, const Rational&);
	friend Rational &operator-=(Rational&, const Rational&);
	friend Rational &operator*=(Rational&, const Rational&);
	friend Rational &operator/=(Rational&, const Rational&);

    /// supraincarcarea operatorilor aritmetici compusi pt (Rational, Rational)
	Rational operator+=(int);
	Rational operator-=(int);
	Rational operator*=(int);
	Rational operator/=(int);

    /// supraincarcarea operatorilor relationali pt (Rational, Rational)
    friend bool operator== (const Rational&, const Rational&);
    friend bool operator!= (const Rational&, const Rational&);
    friend bool operator<  (const Rational&, const Rational&);
    friend bool operator<= (const Rational&, const Rational&);
    friend bool operator>  (const Rational&, const Rational&);
    friend bool operator>= (const Rational&, const Rational&);

    /// supraincarcarea operatorilor relationali pt (Rational, int)
    friend bool operator== (const Rational&, const int);
    friend bool operator!= (const Rational&, const int);
    friend bool operator<  (const Rational&, const int);
    friend bool operator<= (const Rational&, const int);
    friend bool operator>  (const Rational&, const int);
    friend bool operator>= (const Rational&, const int);

    /// supraincarcarea operatorilor relationali pt (int, Rational)
    friend bool operator== (const int, const Rational&);
    friend bool operator!= (const int, const Rational&);
    friend bool operator<  (const int, const Rational&);
    friend bool operator<= (const int, const Rational&);
    friend bool operator>  (const int, const Rational&);
    friend bool operator>= (const int, const Rational&);

    /// supraincarcarea operatorilor aritmetici unari
    Rational operator- ();
    Rational operator+ ();

    /// supraincarcarea operatorului de ridicare la putere ^
    friend Rational operator^ (Rational &, int);

    friend istream &operator>>(istream&, Rational&);

private:
	/// variabile folosite
	int numerator;
	int denominator;
	/// functii ajutatoare

	void simplify();
	int cmmdc(int, int);

};

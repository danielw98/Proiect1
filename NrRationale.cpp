#include <iostream>
#include "NrRationale.h"
#include <cmath>
using namespace std;
/// Cod pt clasa Rational


///Cod pt constructori
Rational::Rational(int m_numerator, int m_denominator)
{
	numerator = m_numerator;
	denominator = m_denominator;
	if (m_denominator == 0)
        cout << "nu puteti imparti la 0!";
	simplify();
}

Rational::Rational(int m_numerator)
{
	numerator = m_numerator;
	denominator = 1;
}

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(double value)
{
	int m_numerator = (int)(value);
	int m_denominator = 1;

	while (abs(value - m_numerator) > 0.00001)
	{
		value *= 10;
		m_numerator = (int)value;
		m_denominator *= 10;
	}
	numerator = m_numerator;
	denominator = m_denominator;
	simplify();
}
/// construnctor de copiere
Rational::Rational (const Rational& obj)
{
    numerator = obj.numerator;
    denominator = obj.denominator;
}

/// cod pt setters & getters
int Rational::getNumerator()
{
	return numerator;
}

int Rational::getDenominator()
{
	return denominator;
}

void Rational::setValue(double value)
{
	numerator = value;
	denominator = 1;
}

double Rational::getValue()
{
	return (double)numerator / denominator;
}

void Rational::setNumerator(int m_numerator)
{
	numerator = m_numerator;
}

void Rational::setDenominator(int m_denominator)
{
	denominator = m_denominator;
}


/// Cod pt supraincarcarea operatorilor aritmetici binari - (Rational,Rational)
Rational &operator+ (const Rational &left, const Rational &right)
{
	Rational temp1, temp2;
	temp1 = left; temp2 = right;
	int commonDen = temp1.getDenominator() * temp2.getDenominator();
	int crtNum = temp1.getNumerator() * temp2.getDenominator() + temp2.getNumerator() * temp1.getDenominator();
	Rational *sum = new Rational(crtNum, commonDen);
	return *sum;
}

Rational &operator- (const Rational &left, const Rational &right)
{
	Rational temp1, temp2;
	temp1 = left; temp2 = right;
	Rational *diff = new Rational;

        if (temp1.getValue() < temp2.getValue())
            {
                *diff = -(temp2 + (-temp1));
                return *diff;
            }
        else
            {
                *diff = temp1+(-temp2);
                    return *diff;
            }
}

Rational &operator* (const Rational &left, const Rational &right)
{
	Rational temp1, temp2;
	temp1 = left; temp2 = right;
	int commonDen = temp1.getDenominator() * temp2.getDenominator();
	int crtNum = temp1.getNumerator() * temp2.getNumerator();
	Rational *prod = new Rational(crtNum, commonDen);
	return *prod;
}

Rational &operator/ (const Rational &left, const Rational &right)
{
	Rational temp1, temp2;
	temp1 = left; temp2 = right;
	int commonDen = temp1.getDenominator() * temp2.getNumerator();
	int crtNum = temp1.getNumerator() * temp2.getDenominator();
	Rational *rezultat = new Rational(crtNum, commonDen);
	return *rezultat;
}


///cod pt supraincarcarea operatorilor aritmetici binari - (Rational, int)
Rational &operator+ (const Rational &left, int right)
{
	Rational temp1, temp2(right, 1);
	temp1 = left;
	return temp1 + temp2;
}

Rational &operator- (const Rational &left, int right)
{
	Rational temp1, temp2(right,1);
	temp1 = left;
	return temp1 - temp2;
}

Rational &operator* (const Rational &left, int right)
{
	Rational temp1, temp2(right,1);
	temp1 = left;
	return temp1 * temp2;
}

Rational &operator/ (const Rational &left, int right)
{
	Rational temp1, temp2(right,1);
	temp1 = left;
	return temp1 / temp2;
}


///cod pt supraincarcarea operatorilor aritmetici binari - (double, Rational)
Rational &operator+(double left, const Rational& right)
{
	Rational temp1 = (Rational)(left);
	Rational temp2 = right;
	return temp1 + temp2;
}

Rational &operator-(double left, const Rational& right)
{
	Rational temp1 = (Rational)(left);
	Rational temp2 = right;
	return temp1 - temp2;
}

Rational &operator*(double left, const Rational& right)
{
	Rational temp1 = (Rational)(left);
	Rational temp2 = right;
	return temp1 * temp2;
}

Rational &operator/(double left, const Rational& right)
{
	Rational temp1 = (Rational)(left);
	Rational temp2 = right;
	return temp1 / temp2;
}


/// Cod pt supraincarcarea operatorilor compusi - (Rational, Rational)
Rational &operator+= (Rational &left, const Rational &right)
{
	left = left + right;
	return left;
}

Rational &operator-= (Rational &left, const Rational &right)
{
	left = left - right;
	return left;
}

Rational &operator*= (Rational &left, const Rational &right)
{
	left = left * right;
	return left;
}

Rational &operator/= (Rational &left, const Rational &right)
{
	left = left / right;
	return left;
}


/// Cod pt supraincarcarea operatorilor compusi - (Rational, int)
Rational Rational :: operator+= (int right)
{
	*this = *this + right;
	return *this;
}
Rational Rational :: operator-= (int right)
{
	*this = *this - right;
	return *this;
}
Rational Rational :: operator*= (int right)
{
	*this = *this * right;
	return *this;
}
Rational Rational :: operator/= (int right)
{
	*this = *this / right;
	return *this;
}


/// cod pt supraincarcarea operatorilor aritmetici unari + -
Rational Rational :: operator-()
{
    this->numerator = -numerator;
    return *this;
}

Rational Rational :: operator+()
{
    return *this;
}


/// cod pt supraincarcarea operatorilor de citire si afisare
ostream &operator<< (ostream &out, Rational &nr)
{
	if (nr.getDenominator() == 1)
	{
		out << nr.getNumerator();
	}
	else
	{
		out << nr.getNumerator() << '/' << nr.getDenominator();
	}
	return out;
}

istream &operator>> (istream &in, Rational &nr)
{
    char c;
    int m = 0, i = 1;
//    while (getchar(c) != ' ') /// 32 - in tabela ASCII, corespunde <space>
        {
            m = m + i * c;
        }
        cout<<m;

        return in;
}



/// functii ajutatoare
int Rational::cmmdc(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void Rational::simplify()
{
	int common_divisor = cmmdc(numerator, denominator);
	numerator /= common_divisor;
	denominator /= common_divisor;
}




///Supraincarcarea operatorilor relationali (Rational, Rational)
bool operator== (const Rational &left, const Rational &right)
{
    int temp1 = left.numerator * right.denominator;
    int temp2 = left.denominator * right.numerator;
    return temp1 == temp2 ;
}

bool operator> (const Rational &left, const Rational &right)
{
    int temp1 = left.numerator * right.denominator;
    int temp2 = left.denominator * right.numerator;
    return temp1 > temp2 ;
}

bool operator< (const Rational &left, const Rational &right)
{
    int temp1 = left.numerator * right.denominator;
    int temp2 = left.denominator * right.numerator;
    return temp1 < temp2 ;
}

bool operator!= (const Rational &left, const Rational &right)
{
    return ! (left == right);
}

bool operator<= (const Rational &left, const Rational &right)
{
    return (left == right) || (left < right);
}

bool operator>= (const Rational &left, const Rational &right)
{
    return (left == right) || (left > right);
}


/// supraincarcarea operatorilor relationali (Rational, int)
bool operator== (const Rational &left, const int right)
{
    int temp1 = left.numerator;
    int temp2 = left.denominator * right;
    return temp1 == temp2 ;
}

bool operator> (const Rational &left, const int right)
{
    int temp1 = left.numerator;
    int temp2 = left.denominator * right;
    return temp1 > temp2 ;
}

bool operator< (const Rational &left, const int right)
{
    int temp1 = left.numerator;
    int temp2 = left.denominator * right;
    return temp1 < temp2 ;
}

bool operator!= (const Rational &left, const int right)
{
    return ! (left == right);
}

bool operator<= (const Rational &left, const int right)
{
    return (left == right) || (left < right);
}

bool operator>= (const Rational &left, const int right)
{
    return (left == right) || (left > right);
}

///Supraincarcarea operatorilor relationali (int, Rational)
bool operator== (const int left, const Rational &right)
{
    int temp1 = left * right.denominator;
    int temp2 = right.numerator;
    return temp1 == temp2 ;
}

bool operator> (const int left, const Rational &right)
{
    int temp1 = left * right.denominator;
    int temp2 = right.numerator;
    return temp1 > temp2 ;
}

bool operator< (const int left, const Rational &right)
{
    int temp1 = left * right.denominator;
    int temp2 = right.numerator;
    return temp1 < temp2 ;
}

bool operator!= (const int left, const Rational &right)
{
    return ! (left == right);
}

bool operator<= (const int left, const Rational &right)
{
    return (left == right) || (left < right);
}

bool operator>= (const int left, const Rational &right)
{
    return (left == right) || (left > right);
}


/// supraincarcarea operatorului de ridicare la putere ^
Rational operator ^(Rational &nr, int a)
{
    int temp;
    if (a < 0)
    {
        temp = nr.numerator;
        nr.numerator = nr.denominator;
        nr.denominator = temp;
        a = -a;
    }
    int powNum = nr.numerator, powDen = nr.denominator;
    while(a > 1)
    {
        nr.numerator *= powNum;
        nr.denominator *=  powDen;
        --a;
    }

    return nr;
}

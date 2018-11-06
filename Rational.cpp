#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include "Rational.h"
/// Cod pt clasa Rational


///Cod pt constructori
    Rational::Rational(int numerator, int denominator)
        {
            m_numerator = numerator;
            m_denominator = denominator;
            if (denominator == 0)
                {
                    throw std :: runtime_error("nu puteti imparti la 0!");
                    m_numerator = 0;
                    m_denominator = 1;
                }

            simplify();
        }

    Rational::Rational(int numerator)
        {
            m_numerator = numerator;
            m_denominator = 1;
        }

    Rational::Rational()
        {
            m_numerator = 0;
            m_denominator = 1;
        }

    Rational::Rational(double value)
        {
            int numerator = (int)(value);
            int denominator = 1;

            while (abs(value - numerator) > 0.00001)
            {
                value *= 10;
                numerator = (int)value;
                denominator *= 10;
            }
            m_numerator = numerator;
            m_denominator = denominator;
            simplify();
        }


/// construnctor de copiere
    Rational::Rational (const Rational& obj)
        {
            m_numerator = obj.m_numerator;
            m_denominator = obj.m_denominator;
        }

/// cod pt setters & getters
    int Rational::getNumerator()
        {
            return m_numerator;
        }

    int Rational::getDenominator()
        {
            return m_denominator;
        }

    void Rational::setValue(double value)
        {
            m_numerator = value;
            m_denominator = 1;
        }

    double Rational::getValue()
        {
            return (double)m_numerator / m_denominator;
        }

    void Rational::setNumerator(int numerator)
        {
            m_numerator = numerator;
        }

    void Rational::setDenominator(int denominator)
        {
            if (denominator == 0)
            {
                throw std :: runtime_error("Can't divide by 0\n");
            }
            m_denominator = denominator;
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
    Rational& Rational :: operator+= (int right)
        {
            *this = *this + right;
                return *this;
        }

    Rational& Rational :: operator-= (int right)
        {
            *this = *this - right;
                return *this;
        }

    Rational& Rational :: operator*= (int right)
        {
            *this = *this * right;
                return *this;
        }

    Rational& Rational :: operator/= (int right)
        {
            *this = *this / right;
                return *this;
        }


/// cod pt supraincarcarea operatorilor aritmetici unari + -
    Rational Rational :: operator-()
        {
            this->m_numerator = -m_numerator;
                return *this;
        }

    Rational Rational :: operator+()
        {
                return *this;
        }


/// functii ajutatoare (private)
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
            int common_divisor = cmmdc(m_numerator, m_denominator);
            m_numerator /= common_divisor;
            m_denominator /= common_divisor;
        }


///Supraincarcarea operatorilor relationali (Rational, Rational)
    bool operator== (const Rational &left, const Rational &right)
        {
            int temp1 = left.m_numerator * right.m_denominator;
            int temp2 = left.m_denominator * right.m_numerator;
                return temp1 == temp2 ;
        }

    bool operator> (const Rational &left, const Rational &right)
        {
            int temp1 = left.m_numerator * right.m_denominator;
            int temp2 = left.m_denominator * right.m_numerator;
                return temp1 > temp2 ;
        }

    bool operator< (const Rational &left, const Rational &right)
        {
            int temp1 = left.m_numerator * right.m_denominator;
            int temp2 = left.m_denominator * right.m_numerator;
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
            int temp1 = left.m_numerator;
            int temp2 = left.m_denominator * right;
                return temp1 == temp2 ;
        }

    bool operator> (const Rational &left, const int right)
        {
            int temp1 = left.m_numerator;
            int temp2 = left.m_denominator * right;
                return temp1 > temp2 ;
        }

    bool operator< (const Rational &left, const int right)
        {
            int temp1 = left.m_numerator;
            int temp2 = left.m_denominator * right;
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
            int temp1 = left * right.m_denominator;
            int temp2 = right.m_numerator;
                return temp1 == temp2 ;
        }

    bool operator> (const int left, const Rational &right)
        {
            int temp1 = left * right.m_denominator;
            int temp2 = right.m_numerator;
                return temp1 > temp2 ;
        }

    bool operator< (const int left, const Rational &right)
        {
            int temp1 = left * right.m_denominator;
            int temp2 = right.m_numerator;
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
    Rational &operator^ (Rational &nr, int a)
        {
            int temp;
            if (a == 0)
            {
                nr.m_numerator = 1;
                nr.m_denominator = 1;
                return nr;
            }
            if (a < 0)
                {
                     if(nr.m_numerator == 0)
                        {
                            throw std::runtime_error("Can't divide by 0\n");
                        }
                    temp = nr.m_numerator;
                    nr.m_numerator = nr.m_denominator;
                    nr.m_denominator = temp;
                    a = -a;
                }


            int powNum = nr.m_numerator, powDen = nr.m_denominator;
            while(a > 1)
                {
                    nr.m_numerator *= powNum;
                    nr.m_denominator *=  powDen;
                    --a;
                }

                return nr;
        }


/// functii publice ale clasei
    std :: string Rational :: ToString()
        {
            std :: string result;
            std :: stringstream stream;


            if (m_denominator == 1)
                {
                    stream << m_numerator;
                    result = stream.str();
                }
            else
                {
                    stream << m_numerator << '/' << m_denominator;
                    result = stream.str();
                }

                return result;
        }

/// supraincarcarea operatorilor de conversie (tip)
    Rational :: operator int()
        {
                return m_numerator / m_denominator;
        }

    Rational :: operator double()
        {
            double value;
            value = (double) m_numerator / m_denominator;
                return value;
        }

    Rational :: operator std :: string()
        {
                return this -> ToString();
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

std::istream &operator>> (std::istream &in, Rational &nr)
        {

            char stream[100], temp[50];
            int n1, n2;

            in.get(stream, 100);
            char *pch  = strtok (stream, "/ ");
            if (pch != NULL)
            {
                strcpy(temp, pch);
                nr.setNumerator(atoi(temp));
            }
            pch = strtok (NULL, " ");
            if (pch != NULL)
            {
                strcpy(temp, pch);
                 nr.setDenominator(atoi(temp));
            }

            if(nr.m_denominator == 0)
                throw std::runtime_error("Can't divide by 0\n");
           // std::cout << nr.m_numerator << "\n" << nr.m_denominator << "\n\n";
   /*         int sign = 1;
            bool denominator_exists = false;
            for(int i; i < stream.size(); ++i)
                {
                    if (stream[i] == '-')
                        {
                            sign = -sign;
                        }
                    if (stream[i] == '/')
                        {
                            denominator_exists = true;
                        }
                }
            if (denominator_exists)
                {
                    size_t slash = stream.find('/'); /// cautam pozitia slash-ului in string
                    nr.m_numerator = sign *  stoi(stream.substr(0, slash)); /// convertim la int substring-ul, tinand cont de semn
                    nr.m_denominator =  stoi (stream.substr(slash+1, stream.length() ) );
                    if (nr.m_denominator == 0)
                        {
                            throw std::  runtime_error(" \nNumitorul nu poate fi 0!\n");
                        }
                }
            else
                {
                    nr.m_numerator = sign * std :: stoi(stream);
                    nr.m_denominator = 1;
                }
*/

                return in;
        }

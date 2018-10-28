#include <iostream>
#include "NrRationale.h"
#include <cmath>
using namespace std;
/// cod pt clasa nr rationale

///cod pt constructor

Rational::Rational(int m_numarator, int m_numitor)
{
    numarator = m_numarator;
    numitor = m_numitor;
    simplifica();
}

Rational::Rational (int m_numarator)
{
    numarator = m_numarator;
    numitor = 1;
}

Rational:: Rational ()
    {
        numarator = 0;
        numitor = 1;
    }

Rational::Rational (double value)
{
   int m_numarator = (int)(value);
   int m_numitor = 1;

   while (abs(value-m_numarator)>0.00001)
   {
       value *= 10;
       m_numarator = (int) value;
       m_numitor *= 10;
   }
   numarator = m_numarator;
   numitor = m_numitor;
   simplifica();
}


/// cod pt setters & getters

int Rational:: getNumarator()
{
    return numarator;
}

int Rational:: getNumitor()
{
    return numitor;
}
void Rational:: setValue (double value)
{
    numarator = value;
    numitor = 1;
}
double Rational::getValue()
{
    return (double)numarator/numitor;
}


void Rational:: setNumarator(int m_numarator)
{
    numarator = m_numarator;
}

void Rational:: setNumitor(int m_numitor)
{
    numitor = m_numitor;
}

Rational &operator+ (const Rational &st, const Rational &dr)
{
    Rational temp1, temp2;
    temp1 = st; temp2 = dr;
    int numitorComun = temp1.getNumitor() * temp2.getNumitor() ;
    int numaratorCrt = temp1.getNumarator() * temp2.getNumitor() + temp2.getNumarator() * temp1.getNumitor();
    Rational *suma = new Rational (numaratorCrt, numitorComun);
    return *suma;
}
Rational &operator- (const Rational &st, const Rational &dr)
{
    Rational temp1, temp2;
    temp1 = st; temp2 = dr;
    int numitorComun = temp1.getNumitor() * temp2.getNumitor() ;
    int numaratorCrt = temp1.getNumarator() * temp2.getNumitor() - temp2.getNumarator() * temp1.getNumitor();
    Rational *diferenta = new Rational (numaratorCrt, numitorComun);
    return *diferenta;
}
Rational &operator* (const Rational &st, const Rational &dr)
{
    Rational temp1, temp2;
    temp1 = st; temp2 = dr;
    int numitorComun = temp1.getNumitor() * temp2.getNumitor() ;
    int numaratorCrt = temp1.getNumarator() * temp2.getNumarator();
    Rational *prod = new Rational (numaratorCrt, numitorComun);
    return *prod;
}
Rational &operator/ (const Rational &st, const Rational &dr)
{
    Rational temp1, temp2;
    temp1 = st; temp2 = dr;
    int numitorComun = temp1.getNumitor() * temp2.getNumarator() ;
    int numaratorCrt = temp1.getNumarator() * temp2.getNumitor();
    Rational *rezultat = new Rational (numaratorCrt, numitorComun);
    return *rezultat;
}

ostream &operator<< (ostream &out, Rational &nr)
{
    out<<nr.getNumarator()<<'/'<<nr.getNumitor();
    return out;
}

int Rational:: cmmdc(int a, int b)
{
   while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
void Rational:: simplifica()
{
    int divizor_comun = cmmdc(numarator, numitor);
    numarator /= divizor_comun;
    numitor /= divizor_comun;
}

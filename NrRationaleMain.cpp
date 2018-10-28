#include "NrRationale.cpp"
using namespace std;

int main ()
{
    cout<<"Verificare pentru constructori:\n";
    Rational r1(3,2);
    Rational r2;
    Rational r3(3.14);
    Rational r4(12);
    Rational r5(4,6);
    cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;

    cout<<"\nSupraincarcarea operatorilor aritmetici binari +, -, *, /: "<<r1<<" "<<r5<<endl;
    Rational r6 = r1 + r5 ;
    Rational r7 = r1 - r5;
    Rational r8 = r1 * r5;
    Rational r9 = r1 / r5;
    cout<<r6<<'\t'<<r7<<'\t'<<r8<<'\t'<<r9<<endl;


    Rational r10(5,2);
    Rational r11(2);
    cout<<"\nSupraincarcarea operatorilor compusi de atribuire +=, -=, *=, /=: "<<r10<<" "<<r11<<endl;
    r6 = r10; r7 = r10; r8 = r10; r9 = r10;
    r6 += r11;
    r7 -= r11;
    r8 *= r11;
    r9 /= r11;
    cout<<r6<<'\t'<<r7<<'\t'<<r8<<'\t'<<r9<<endl;


    int k = 2;

    cout<<"\nSupraincarcarea operatorilor aritmetici binari +, -, *, / pentru numere intregi: "<<r10<<" "<<k<<endl;
    r6 = r10 + k;
    r7 = r10 - k;
    r8 = r10 * k;
    r9 = r10 / k;
    cout<<r6<<'\t'<<r7<<'\t'<<r8<<'\t'<<r9<<endl;

    cout<<"\nSupraincarcarea operatorilor compusi de atribuire +=, -=, *=, /= pentru nr intregi: "<<r10<<" "<<k<<endl;
    r6 = r10; r7 = r10; r8 = r10; r9 = r10;
    r6 += k;
    r7 -= k;
    r8 *= k;
    r9 /= k;
    cout<<r6<<'\t'<<r7<<'\t'<<r8<<'\t'<<r9<<endl;


    double m = 3.5;
    cout<<"\nSupraincarcarea operatorilor aritmetici binari +, -, *, / pentru nr reale: "<<m<<" "<<r10<<endl;
    r6 = m + r10;
    r7 = m - r10;
    r8 = m * r10;
    r9 = m / r10;
    cout<<r6<<'\t'<<r7<<'\t'<<r8<<'\t'<<r9<<endl;


    return 0;
}

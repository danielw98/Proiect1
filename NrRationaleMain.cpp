#include "NrRationale.cpp"
using namespace std;

int main ()
{
    cout<<"Verificare pentru constructori:\n";
    Rational r1(3,2);
    Rational r2;
    Rational r3(3.14);
    Rational r4(12);
    Rational r5(5,2);
    cout<<r1<<'\t'<<r2<<'\t'<<r3<<'\t'<<r4<<endl;

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


    int k = 3;

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

cout<<"\nSupraincarcarea operatorilor relationali ==, <, >, <=, >=, != : \n";
Rational r25;
Rational r26(3,2), r27(5,2), r28(3,2), r29(1,2);
bool m1 = (r26 < r27), m2 = (r26 == r28), m3 = (r26 != r27), m4 = (r26 > r28), m5 = (r26 >= r28), m6 = (r26 <= r29);
cout << r26 << "  <   " << r27 << '\t' << m1 <<endl;
cout << r26 << "  ==  " << r28 << '\t' << m2<<endl;
cout << r26 << "  !=  " << r27 << '\t' << m3<<endl;
cout << r26 << "  >   " << r28 << '\t' << m4<<endl;
cout << r26 << "  >=  " << r28 << '\t' << m5<<endl;
cout << r26 << "  <=  " << r29 << '\t' << m6<<endl;


int a = -1;
Rational r30;
r30 = r26 ^a;
cout<<'\n'<<r30;
    return 0;
}

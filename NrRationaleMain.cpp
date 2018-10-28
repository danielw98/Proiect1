#include "NrRationale.cpp"
using namespace std;

int main ()
{
    cout<<"Verificare pentru constructori:\n";
    Rational r1(3,2);
    Rational r2;
    Rational r3(3.13);
    Rational r4(12);
    Rational r5(4,6);
    cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;

    cout<<"\nVerificare pt supraincarcare de operatori (si simplificare fractii): "<<r1<<" "<<r5<<endl;
    Rational r6 = r1 + r5;
    Rational r7 = r1 - r5;
    Rational r8 = r1 * r5;
    Rational r9 = r1 / r5;
    cout<<r6<<" "<<r7<<" "<<r8<<" "<<r9<<endl;

    return 0;

}

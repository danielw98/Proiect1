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

    cout<<"\nVerificare pt supraincarcarea operatorilor aritmetici binari +, -, *, / : "<<r1<<" "<<r5<<endl;
    Rational r6 = r1 + r5 ;
    Rational r7 = r1 - r5;
    Rational r8 = r1 * r5;
    Rational r9 = r1 / r5;
    cout<<r6<<" "<<r7<<" "<<r8<<" "<<r9<<endl;


    Rational r10(5,2);
    Rational r11(1,2);
    cout<<"\nVerificare pt supraincarcarea operatorilor compusi de atribuire +=, -=, *=, /= : "<<r10<<" "<<r11<<endl;
    Rational r12 = r10, r13 = r10, r14 = r10, r15 = r10;
    r12 += r11;
    r13 -= r11;
    r14 *= r11;
    r15 /= r11;
    cout<<r12<<" "<<r13<<" "<<r14<<" "<<r15<<endl;
    int k = 2;
    cout<<"\nSupraincarcarea operatorilor compusi de atribuire pentru nr intregi: "<<r10<<" "<<k<<endl;
    Rational r16 = r10, r17 = r10, r18 = r10, r19 = r10;
    r16+=k;
    r17-=k;
    r18*=k;
    r19/=k;
    cout<<r16<<" "<<r17<<" "<<r18<<" "<<r19<<endl;
    return 0;

}

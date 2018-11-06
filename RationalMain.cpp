#include "Rational.cpp"

int main ()
    {

/********************************************************************************/
        std :: cout << "Verificare pentru constructori:\n";
            Rational r1(3,2);
            Rational r2;
            Rational r3(3.14);
            Rational r4(12);
            Rational r5(5,2);
        std :: cout << r1 << '\t' << r2 << '\t' << r3 << '\t' << r4 << endl;


/********************************************************************************/
        std :: cout << "\nSupraincarcarea operatorilor aritmetici binari +, -, *, /: " << r1 << " " << r5 << endl;
            Rational r6 = r1 + r5 ;
            Rational r7 = r1 - r5;
            Rational r8 = r1 * r5;
            Rational r9 = r1 / r5;
        std :: cout << r6 << '\t' << r7 << '\t' << r8 << '\t' << r9 << endl;


/********************************************************************************/
            Rational r10(5,2);
            Rational r11(2);
        std :: cout << "\nSupraincarcarea operatorilor compusi de atribuire +=, -=, *=, /=: " << r10 << " " << r11 << endl;
            r6 = r10; r7 = r10; r8 = r10; r9 = r10;
            r6 += r11;
            r7 -= r11;
            r8 *= r11;
            r9 /= r11;
        std :: cout << r6 << '\t' << r7 << '\t' << r8 << '\t' << r9 << endl;


/********************************************************************************/
            int k = 3;
        std :: cout << "\nSupraincarcarea operatorilor aritmetici binari +, -, *, / pentru numere intregi: " << r10 << " " << k << endl;
            r6 = r10 + k;
            r7 = r10 - k;
            r8 = r10 * k;
            r9 = r10 / k;
        std :: cout << r6 << '\t' << r7 << '\t' << r8 << '\t' << r9 << endl;


/********************************************************************************/
        std :: cout << "\nSupraincarcarea operatorilor compusi de atribuire +=, -=, *=, /= pentru nr intregi: " << r10 << " " <<k << endl;
            r6 = r10; r7 = r10; r8 = r10; r9 = r10;
            r6 += k;
            r7 -= k;
            r8 *= k;
            r9 /= k;
        std :: cout << r6 << '\t' << r7 << '\t' << r8 << '\t' << r9 << endl;


/********************************************************************************/
            double m = 3.5;
        std :: cout<<"\nSupraincarcarea operatorilor aritmetici binari +, -, *, / pentru nr reale: "<<m<<" "<<r10<<endl;
            r6 = m + r10;
            r7 = m - r10;
            r8 = m * r10;
            r9 = m / r10;
        std :: cout<<r6<<'\t'<<r7<<'\t'<<r8<<'\t'<<r9<<endl;


/********************************************************************************/
        std :: cout<<"\nSupraincarcarea operatorilor relationali ==, <, >, <=, >=, != (Rational, Rational) : \n";
            Rational r25;
            Rational r26(3,2), r27(5,2), r28(3,2), r29(1,2);
            bool m1 = (r26 < r27), m2 = (r26 == r28), m3 = (r26 != r27), m4 = (r26 > r28), m5 = (r26 >= r28), m6 = (r26 <= r29);
        std :: cout << r26 << "  <   " << r27 << '\t' << m1 <<endl;
        std :: cout << r26 << "  ==  " << r28 << '\t' << m2<<endl;
        std :: cout << r26 << "  !=  " << r27 << '\t' << m3<<endl;
        std :: cout << r26 << "  >   " << r28 << '\t' << m4<<endl;
        std :: cout << r26 << "  >=  " << r28 << '\t' << m5<<endl;
        std :: cout << r26 << "  <=  " << r29 << '\t' << m6<<endl;


/********************************************************************************/
        std :: cout<<"\nSupraincarcarea operatorilor relationali ==, <, >, <=, >=, != (Rational, int) : \n";
            m1 = (r26 < 2), m2 = (r29 == 2), m3 = (r29 != 3), m4 = (r26 > 1), m5 = (r26 >= 3), m6 = (r29 <= 1);
        std :: cout << r26 << "  <   " << 2 << '\t' << m1<<endl;
        std :: cout << r29 << "  ==  " << 2 << '\t' << m2<<endl;
        std :: cout << r29 << "  !=  " << 3 << '\t' << m3<<endl;
        std :: cout << r26 << "  >   " << 1 << '\t' << m4<<endl;
        std :: cout << r26 << "  >=  " << 3 << '\t' << m5<<endl;
        std :: cout << r29 << "  <=  " << 1 << '\t' << m6<<endl;


/********************************************************************************/
        std :: cout<<"\nSupraincarcarea operatorilor relationali ==, <, >, <=, >=, != (int, Rational) : \n";
            m1 = (2 < r26), m2 = (2 == r29), m3 = (3 != r29), m4 = (1 > r26), m5 = (3 >= r26), m6 = (1 <= r29);
        std :: cout << 2 << "  <   " << r26 << '\t' << m1<<endl;
        std :: cout << 2 << "  ==  " << r29 << '\t' << m2<<endl;
        std :: cout << 3 << "  !=  " << r29 << '\t' << m3<<endl;
        std :: cout << 1 << "  >   " << r26 << '\t' << m4<<endl;
        std :: cout << 3 << "  >=  " << r26 << '\t' << m5<<endl;
        std :: cout << 1 << "  <=  " << r29 << '\t' << m6<<endl;


/********************************************************************************/
        std :: cout << "\nRidicarea unui nr rational la o putere: \n";
            int a = -3, b = 2, c = 0;
            Rational r30, temp = r26;

        std :: cout << r26 << " ^ "  << a << " = ";
            r30 = r26^a, r26 = temp;
        std :: cout << r30 << endl;

        std :: cout << r26 << " ^  " << b << " = ";
            r30 = r26^b, r26 = temp;
        std :: cout << r30 << endl;

        std :: cout << r26 << " ^  " << c << " = ";
            r30 = r26^c, r26 = temp;
        std :: cout << r30 << endl;


/********************************************************************************/
        std :: cout << "\nSupraincarcarea operatorilor de conversie la (tip): \n";
            int r50 = (int)r10;
        std :: cout << "Pentru int:     " << r10 << " devine " << r50   << endl;
            double value = (double)r10;
        std :: cout << "Pentru double:  " << r10 << " devine " << value << endl;
            std :: string str = (std :: string) r10;
        std :: cout << "Pentru string:  " << r10 << " devine " << str   << endl;


/********************************************************************************/
            Rational r40;
        std :: cout << "\n\nIntroduceti un nr rational: ";
        try
            {
                std :: cin >> r40;
            }
        catch (const exception & e)
            {
                std::cout << e.what() << "\n";
            }
        std :: cout << "Numarul introdus este " << r40<<endl;
            return 0;


    }

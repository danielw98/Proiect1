

class Rational
{

public:


    /// constructori
    Rational ();
    Rational (int m_numarator, int m_numitor);
    Rational (double value);
    Rational (int m_numarator);

    /// setteri si getteri

    void setValue(double value);
    double getValue();
    void setNumarator(int m_numarator);
    int getNumarator();
    void setNumitor(int m_numitor);
    int getNumitor();

    friend Rational &operator+(const Rational& st, const Rational& dr);
    friend Rational &operator-(const Rational& st, const Rational& dr);
    friend Rational &operator*(const Rational& st, const Rational& dr);
    friend Rational &operator/(const Rational& st, const Rational& dr);

private:
    /// variabile folosite
    int numarator;
    int numitor;
    /// functii ajutatoare

    void simplifica();
    int cmmdc(int a, int b);
};


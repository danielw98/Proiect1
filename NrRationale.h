

class Rational
{

public:


    /// constructori
    Rational (int m_numarator, int m_numitor);
    Rational ();
    Rational (double value);
    Rational (int m_numarator);

    /// setteri si getteri

    void setValue(int m_numarator, int m_numitor);
    double getValue();
    void setNumarator(int m_numarator);
    int getNumarator();
    void setNumitor(int m_numitor);
    int getNumitor();
    void simplifica();

    friend Rational &operator+(const Rational& st, const Rational& dr);
    friend Rational &operator-(const Rational& st, const Rational& dr);
    friend Rational &operator*(const Rational& st, const Rational& dr);
    friend Rational &operator/(const Rational& st, const Rational& dr);

private:
    /// variabile folosite
    int numarator;
    int numitor;
    /// functii ajutatoare

    int cmmdc(int a, int b);
};


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

        /// functii prietene (pentru supraincarcare de operatori)
        friend Rational &operator+(const Rational&, const Rational&);
        friend Rational &operator-(const Rational&, const Rational&);
        friend Rational &operator*(const Rational&, const Rational&);
        friend Rational &operator/(const Rational&, const Rational&);

        friend Rational &operator+(double, const Rational&);
        friend Rational &operator-(double, const Rational&);
        friend Rational &operator*(double, const Rational&);
        friend Rational &operator/(double, const Rational&);

        friend Rational &operator+(const Rational&, int);
        friend Rational &operator-(const Rational&, int);
        friend Rational &operator*(const Rational&, int);
        friend Rational &operator/(const Rational&, int);

        friend Rational &operator+=(Rational&, const Rational&);
        friend Rational &operator-=(Rational&, const Rational&);
        friend Rational &operator*=(Rational&, const Rational&);
        friend Rational &operator/=(Rational&, const Rational&);

        friend Rational &operator+=(Rational&, int);
        friend Rational &operator-=(Rational&, int);
        friend Rational &operator*=(Rational&, int);
        friend Rational &operator/=(Rational&, int);




    private:
        /// variabile folosite
        int numarator;
        int numitor;
        /// functii ajutatoare

        void simplifica();
        int cmmdc(int a, int b);
};


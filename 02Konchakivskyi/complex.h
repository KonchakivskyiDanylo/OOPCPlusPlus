#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cassert>
#include <cmath>

class AComplex;
class TComplex;

class AComplex {
private:
    double re;
    double im;

public:
    AComplex();
    AComplex(double real, double imag = 0.0);
    AComplex(const AComplex& other);
    AComplex(const TComplex& tcomp);

    double real() const;
    double imag() const;

    double modulus() const;
    double argument() const;

    AComplex operator+(const AComplex& other) const;
    AComplex operator-(const AComplex& other) const;

    AComplex& operator+=(const AComplex& other);
    AComplex& operator-=(const AComplex& other);

    AComplex pow(double exponent) const;


    friend AComplex operator+(double scalar, const AComplex& comp);
    friend AComplex operator-(double scalar, const AComplex& comp);

    friend std::ostream& operator<<(std::ostream& os, const AComplex& comp);

    friend class TComplex;
};

class TComplex {
private:
    double r;
    double theta;

public:
    TComplex();
    TComplex(double radius, double angle);
    TComplex(const TComplex& other);
    TComplex(const AComplex& acomp);

    double modulus() const;
    double argument() const;

    TComplex operator*(const TComplex& other) const;
    TComplex operator/(const TComplex& other) const;

    TComplex& operator*=(const TComplex& other);
    TComplex& operator/=(const TComplex& other);

    friend TComplex operator*(double scalar, const TComplex& comp);
    friend TComplex operator/(double scalar, const TComplex& comp);

    TComplex pow(double exponent) const;

    AComplex toAComplex() const;

    friend std::ostream& operator<<(std::ostream& os, const TComplex& comp);

    friend class AComplex;
};

#endif
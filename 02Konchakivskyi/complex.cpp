#include "complex.h"


AComplex::AComplex() : re(0.0), im(0.0) {}

AComplex::AComplex(double real, double imag) : re(real), im(imag) {}

AComplex::AComplex(const AComplex& other) : re(other.re), im(other.im) {}

AComplex::AComplex(const TComplex& t) {
    re = t.r * std::cos(t.theta);
    im = t.r * std::sin(t.theta);
}

double AComplex::real() const {
    return re;
}

double AComplex::imag() const {
    return im;
}

double AComplex::modulus() const {
    return std::sqrt(re * re + im * im);
}

double AComplex::argument() const {
    return std::atan2(im, re);
}

AComplex AComplex::operator+(const AComplex& other) const {
    return AComplex(re + other.re, im + other.im);
}

AComplex AComplex::operator-(const AComplex& other) const {
    return AComplex(re - other.re, im - other.im);
}

AComplex& AComplex::operator+=(const AComplex& other) {
    re += other.re;
    im += other.im;
    return *this;
}

AComplex& AComplex::operator-=(const AComplex& other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

AComplex AComplex::pow(double exponent) const {
    double mod = this->modulus();
    double arg = this->argument();

    double new_mod = std::pow(mod, exponent);
    double new_arg = arg * exponent;

    return AComplex(new_mod * std::cos(new_arg), new_mod * std::sin(new_arg));
}

AComplex operator+(double scalar, const AComplex& comp) {
    return AComplex(scalar + comp.re, comp.im);
}

AComplex operator-(double scalar, const AComplex& comp) {
    return AComplex(scalar - comp.re, -comp.im);
}

std::ostream& operator<<(std::ostream& os, const AComplex& comp) {
    if (comp.im >= 0) {
        os << comp.re << " + " << comp.im << "i";
    }
    else {
        os << comp.re << " - " << -comp.im << "i";
    }
    return os;
}


TComplex::TComplex() : r(0.0), theta(0.0) {}

TComplex::TComplex(double r, double phi) : r(r), theta(phi) {}

TComplex::TComplex(const TComplex& other) : r(other.r), theta(other.theta) {}

TComplex::TComplex(const AComplex& acomp) : r(acomp.modulus()), theta(acomp.argument()) {}

double TComplex::modulus() const {
    return r;
}

double TComplex::argument() const {
    return theta;
}

TComplex TComplex::operator*(const TComplex& other) const {
    return TComplex(r * other.r, theta + other.theta);
}

TComplex TComplex::operator/(const TComplex& other) const {
    assert(other.r != 0);
    return TComplex(r / other.r, theta - other.theta);
}

TComplex& TComplex::operator*=(const TComplex& other) {
    r *= other.r;
    theta += other.theta;
    return *this;
}

TComplex& TComplex::operator/=(const TComplex& other) {
    assert(other.r != 0);
    r /= other.r;
    theta -= other.theta;
    return *this;
}

TComplex TComplex::pow(double exponent) const {
    return TComplex(std::pow(r, exponent), theta * exponent);
}

TComplex operator*(double scalar, const TComplex& comp) {
    return TComplex(scalar * comp.r, comp.theta);
}

TComplex operator/(double scalar, const TComplex& comp) {
    assert(comp.r != 0);
    return TComplex(scalar / comp.r, -comp.theta);
}

AComplex TComplex::toAComplex() const {
    return AComplex(r * std::cos(theta), r * std::sin(theta));
}

std::ostream& operator<<(std::ostream& os, const TComplex& comp) {
    os << comp.r << " * (cos(" << comp.theta << ") + i*sin(" << comp.theta << "))";
    return os;
}


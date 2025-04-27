#define _USE_MATH_DEFINES
#include <cmath>
#include "complex.h"

int main() {
    AComplex a1(3.0, 4.0);
    AComplex a2(1.0, -2.0);
    std::cout << "a1 = " << a1 << std::endl;
    std::cout << "a2 = " << a2 << std::endl;

    AComplex a3 = a1 + a2;
    std::cout << "a1 + a2 = " << a3 << std::endl;

    AComplex a4 = a1 - a2;
    std::cout << "a1 - a2 = " << a4 << std::endl;

    a1 += a2;
    std::cout << "a1 += a2: a1 = " << a1 << std::endl;

    a1 -= a2;
    std::cout << "a1 -= a2: a1 = " << a1 << std::endl;

    AComplex a5 = 5.0 + a1;
    std::cout << "5.0 + a1 = " << a5 << std::endl;

    TComplex t1(5.0, M_PI / 4);
    TComplex t2(2.0, M_PI / 6);
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;
    std::cout << "t1 in algebraic form = " << t1.toAComplex() << std::endl;

    TComplex t3 = t1 * t2;
    std::cout << "t1 * t2 = " << t3 << std::endl;
    std::cout << "t1 * t2 in algebraic form = " << t3.toAComplex() << std::endl;

    TComplex t4 = t1 / t2;
    std::cout << "t1 / t2 = " << t4 << std::endl;

    t1 *= t2;
    std::cout << "t1 *= t2: t1 = " << t1 << std::endl;

    t1 /= t2;
    std::cout << "t1 /= t2: t1 = " << t1 << std::endl;

    TComplex t5 = 3.0 * t1;
    std::cout << "3.0 * t1 = " << t5 << std::endl;

    AComplex a6 = t1;
    std::cout << "a6 = t1: " << a6 << std::endl;

    TComplex t6 = a1;
    std::cout << "t6 = a1: " << t6 << std::endl;

    AComplex a7 = a1 + t2.toAComplex();
    std::cout << "a1 + t2 (as AComplex) = " << a7 << std::endl;

    TComplex t7 = t1 * AComplex(2.0, 2.0);
    std::cout << "t1 * AComplex(2.0, 2.0) = " << t7 << std::endl;

    AComplex a8 = a1.pow(2);
    std::cout << "a1^2 = " << a8 << std::endl;

    AComplex a9 = a1.pow(-1);
    std::cout << "a1^(-1) = " << a9 << std::endl;

    AComplex a10 = a1.pow(0.5);
    std::cout << "a1^(0.5) = " << a10 << std::endl;

    TComplex t8 = t1.pow(2);
    std::cout << "t1^2 = " << t8 << std::endl;
    std::cout << "t1^2 in algebraic form = " << t8.toAComplex() << std::endl;

    TComplex t9 = t1.pow(-1);
    std::cout << "t1^(-1) = " << t9 << std::endl;

    TComplex t10 = t1.pow(0.5);
    std::cout << "t1^(0.5) = " << t10 << std::endl;

    return 0;
}
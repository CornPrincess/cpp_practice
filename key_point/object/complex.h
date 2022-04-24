//
// Created by 周天斌 on 2022/4/6.
//

#ifndef CPP_PRACTICE_COMPLES_H
#define CPP_PRACTICE_COMPLES_H

#include <iostream>
#include <cmath>

class complex {
private:
    double re;
    double im;

public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}

    complex &operator+=(const complex &);

    complex &operator-=(const complex &);

    complex &operator*=(const complex &);

    complex &operator/=(const complex &);

    double real() const { return re; }

    double imag() const { return im; }

    friend std::ostream &operator<<(std::ostream &, const complex &);

private:
    friend complex &__doapl(complex *, const complex &);

    friend complex &__doapmi(complex *, const complex &);

    friend complex &__doaml(complex *, const complex &);
};

std::ostream &operator<<(std::ostream &os, const complex &x) {
    os << "(" << x.real() << ", " << x.imag() << ")" << std::endl;
    return os;
}

complex &__doapl(complex *ths, const complex &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

complex &complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

complex &__doapmi(complex *ths, const complex &r) {
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

complex &complex::operator-=(const complex &r) {
    return __doapmi(this, r);
}

complex &__doaml(complex *ths, const complex &r) {
    double f = ths->re * r.re - ths->im * r.im;
    ths->im = ths->re * r.im + ths->im * r.re;
    ths->re = f;
    return *ths;
}

complex &complex::operator*=(const complex &r) {
    return __doaml(this, r);
}

inline double imag(const complex &x) {
    return x.imag();
}

inline double real(const complex &x) {
    return x.real();
}

inline complex operator+(const complex &x, const complex &y) {
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator+(const complex &x, double y) {
    return complex(real(x) + y, imag(x));
}

inline complex operator+(double x, const complex &y) {
    return complex(x + real(y), imag(y));
}

inline complex
operator-(const complex &x, const complex &y) {
    return complex(real(x) - real(y), imag(x) - imag(y));
}

inline complex
operator-(const complex &x, double y) {
    return complex(real(x) - y, imag(x));
}

inline complex
operator-(double x, const complex &y) {
    return complex(x - real(y), -imag(y));
}

inline complex
operator*(const complex &x, const complex &y) {
    return complex(real(x) * real(y) - imag(x) * imag(y),
                   real(x) * imag(y) + imag(x) * real(y));
}

inline complex
operator*(const complex &x, double y) {
    return complex(real(x) * y, imag(x) * y);
}

inline complex
operator*(double x, const complex &y) {
    return complex(x * real(y), x * imag(y));
}

complex
operator/(const complex &x, double y) {
    return complex(real(x) / y, imag(x) / y);
}

inline complex
operator+(const complex &x) {
    return x;
}

inline complex
operator-(const complex &x) {
    return complex(-real(x), -imag(x));
}

inline bool
operator==(const complex &x, const complex &y) {
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator==(const complex &x, double y) {
    return real(x) == y && imag(x) == 0;
}

inline bool
operator==(double x, const complex &y) {
    return x == real(y) && imag(y) == 0;
}

inline bool
operator!=(const complex &x, const complex &y) {
    return real(x) != real(y) || imag(x) != imag(y);
}

inline bool
operator!=(const complex &x, double y) {
    return real(x) != y || imag(x) != 0;
}

inline bool
operator!=(double x, const complex &y) {
    return x != real(y) || imag(y) != 0;
}

inline complex
polar(double r, double t) {
    return complex(r * cos(t), r * sin(t));
}

inline complex
conj(const complex &x) {
    return complex(real(x), -imag(x));
}

inline double
norm(const complex &x) {
    return real(x) * real(x) + imag(x) * imag(x);
}

#endif //CPP_PRACTICE_COMPLES_H

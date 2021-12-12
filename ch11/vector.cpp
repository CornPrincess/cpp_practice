//
// Created by 周天斌 on 2021/12/11.
//

#include <cmath>
#include "vector.h"

using std::sqrt;
using std::cout;

namespace VECTOR {
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);
    // should be about 57.2957795130823

    // private methods for setting values
    void Vector::set_ang() {
        if (x == 0.0 && y == 0.0) {
            ang = 0.0;
        } else {
            ang = atan2(y, x);
        }
    }

    void Vector::set_mag() {
        mag = sqrt(x * x + y * y);
    }

    // set x from polar coordinate
    void Vector::set_x() {
        x = mag * cos(ang);
    }

    // set y from polar coordinate
    void Vector::set_y() {
        y = mag * sin(ang);
    }

    // public methods
    // default constructor
    Vector::Vector() {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL) {
            mag = n1;
            ang = n2 / Rad_to_deg;;
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    // reset vector from rectangular coordinates if form is
    // RECT (the default) or else from polar coordinates if
    // form is POL
    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL) {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    // destructor
    Vector::~Vector() {

    }

    // set to polar mode
    void Vector::polar_mode() {
        mode = POL;
    }

    // set to rectangular mode
    void Vector::rect_mode() {
        mode = RECT;
    }

    // operator overloading
    Vector Vector::operator*(double n) const {
        return Vector(x * n, y * n);
    }

    Vector Vector::operator+(const Vector &b) const {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b) const {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }

    // friends method
    Vector operator*(double n, const Vector &a) {
        return a * n;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &v) {
        // core 这里是友元函数，不在类作用域内，因此必须使用 vector::RECT
        if (v.mode == Vector::RECT) {
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        } else if (v.mode == Vector::POL) {
            os << "(m,a) = (" << v.mag << ", "
               << v.ang * Rad_to_deg << ")";
        } else
            os << "Vector object mode is invalid";
        return os;
    }
}
//
// Created by 周天斌 on 2021/12/9.
//

#ifndef CPP_PRACTICE_VECTOR_H
#define CPP_PRACTICE_VECTOR_H

namespace VECTOR {
    class Vector {
    public:
        enum Mode {
            RECT, POL
        };
    private:
        double x;
        double xy;
        double mag;
        double ang;
        Mode mode;

        // private methods for setting values
        void set_mag();

        void set_ang();

        void set_x();

        void set_y();

    public:
        Vector();

        Vector(double n1, double n2, Mode form = RECT);

        void reset(double n1, double n2, Mode form = RECT);

        ~Vector();

        double xval() const { return x; }     // report x value
        double yval() const { return y; }     // report y value
        double magval() const { return mag; } // report magnitude
        double angval() const { return ang; } // report angle
        void polar_mode();                  // set mode to POL
        void rect_mode();                   // set mode to RECT
        // operator overloading
        Vector operator+(const Vector &b) const;

        Vector operator-(const Vector &b) const;

        Vector operator-() const;

        Vector operator*(double n) const;

        // friends
        friend Vector operator*(double n, const Vector &a);

        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    };
}

#endif //CPP_PRACTICE_VECTOR_H

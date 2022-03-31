//
// Created by 周天斌 on 2021/12/9.
//

#ifndef CPP_PRACTICE_MYTIME3_H
#define CPP_PRACTICE_MYTIME3_H

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    Time(int h, int m = 0);

    void AddMin(int m);

    void AddHr(int h);

    void Reset(int h = 0, int m = 0);

    Time operator+(const Time &t) const;

    Time operator-(const Time &t) const;

    Time operator*(double n) const;

    // inline definition
    friend Time operator*(double m, const Time &t) {
        // return t.operator*(m); ok
        return t * m;
    }

    friend std::ostream &operator<<(std::ostream &os, const Time &t);
};

#endif //CPP_PRACTICE_MYTIME3_H

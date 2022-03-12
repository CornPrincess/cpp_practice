//
// Created by 周天斌 on 2022/3/12.
//

#include "timer.h"
#include <iostream>

using namespace std;
Time::Time() {
    hour = minutes = 0;
}

Time::Time(int h, int m) {
    hour = h;
    minutes = m;
}

Time Time::operator+(const Time &t) {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hour = hour + t.hour + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::operator()(int h, int m) {
    this->hour = h;
    this->minutes = m;
}

void Time::show() const {
    cout << hour << "hours, " << minutes << "minutes" << endl;
}

int main() {
    Time t1(10, 10);
    Time t2(11, 11);
    Time t3;

    t1.show();
    t2.show();
    t3.show();

    t3 = t1 + t2;
    t3.show();

    t3 = t1.operator+(t2);
    t3.show();

    t3.operator()(0, 0);
    t3.show();

    t3(1, 1);
    t3.show();
    return 0;
}
//
// Created by 周天斌 on 2021/12/9.
//

#ifndef CPP_PRACTICE_MYTIME2_H
#define CPP_PRACTICE_MYTIME2_H

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


    void Show() const;
};

#endif //CPP_PRACTICE_MYTIME2_H

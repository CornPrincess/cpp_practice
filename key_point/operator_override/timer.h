//
// Created by 周天斌 on 2022/3/12.
//

#ifndef CPP_PRACTICE_TIMER_H
#define CPP_PRACTICE_TIMER_H
class Time {
private:
    int hour;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void show() const;
    Time operator+(const Time & t);
    void operator()(int h, int m);
};
#endif //CPP_PRACTICE_TIMER_H

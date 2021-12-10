//
// Created by 周天斌 on 2021/12/5.
// structure  templates and function prototypes

#ifndef CPP_PRACTICE_COORDIN_H
#define CPP_PRACTICE_COORDIN_H

struct polar {
    double distance;
    double angle;
};

struct rect {
    double x;
    double y;
};

// prototypes
polar rect_to_polar(rect xpos);
void show_polar(polar dapos);

#endif //CPP_PRACTICE_COORDIN_H

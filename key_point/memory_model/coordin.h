//
// Created by 周天斌 on 2022/1/26.
//

#ifndef CPP_PRACTICE_COORDIN_H
#define CPP_PRACTICE_COORDIN_H

struct polar {
    // distance from origin
    double distance;
    // direction from origin
    double angle;
};

struct rect {
    // horizontal distance from origin
    double x;
    // vertical distance from origin
    double y;
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif //CPP_PRACTICE_COORDIN_H

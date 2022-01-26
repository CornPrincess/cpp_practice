//
// Created by 周天斌 on 2022/1/26.
//

#include <iostream>
#include <cmath>
#include "coordin.h"

polar rect_to_polar(rect xypos) {
    polar answer;

    answer.distance = std::sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.x, xypos.y);
    return answer;
}

void show_polar(polar dapos) {
    const double Rad_to_deg = 57.29577951;

    std::cout << "distance = " << dapos.distance;
    std::cout << ", angle = " << dapos.angle * Rad_to_deg;
    std::cout << " degrees\n";
}
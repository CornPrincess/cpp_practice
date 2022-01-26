//
// Created by 周天斌 on 2021/12/27.
//

#include "worker0.h"
#include <iostream>

const int LTM = 4;

int main() {
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter w_temp;
    Singer s_temp;

    Worker *pw[LTM] = {&bob, &bev, &w_temp, &s_temp};

    int i;
    for (i = 2; i < LTM; i++) {
        pw[i]->Set();
    }
    for (i = 0; i < LTM; i++) {
        pw[i]->Show();
        std::cout << std::endl;
    }

    return 0;
}
//
// Created by 周天斌 on 2022/2/10.
//

#include <iostream>

struct ball {
    int a;
};

ball & f(ball & b) {
    b.a = 3;
    return b;
}

const ball & f2(ball & b) {
    b.a = 3;
    return b;
}

int main() {
    ball ball_0 = {1};
    ball ball_1 = {2};
    f(ball_0) = ball_1; // f(ball_0) 返回的引用，表示了一个可修改的内存块，是左值，因此可以防在语句左边

    std::cout << ball_0.a << std::endl; // 2
    std::cout << ball_1.a << std::endl; // 2

    // compiler error
    // f2(ball_0) = ball_1; // 返回的是不可修改的左值，因此编译报错
    return 0;
}
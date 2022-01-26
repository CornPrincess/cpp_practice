//
// Created by 周天斌 on 2022/1/25.
//

#include <iostream>

int main() {
    const int a = 7;
    int *p = (int *) &a;
    int c = a;
    *p = 8;
    int d = a;
    std::cout << *p << std::endl; // 8
    std::cout << a << std::endl; // 7
    std::cout << c << std::endl; // 7
    std::cout << d << std::endl; // 7
    return 0;
}
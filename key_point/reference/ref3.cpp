//
// Created by 周天斌 on 2022/2/10.
//

#include <iostream>

bool f(int &r);
void t(int &r);

int main() {
    int &r = *static_cast<int *>(nullptr);

    // null
    std::cout
            << (&r != nullptr
                ? "not null" : "null")
            << std::endl;


    // null
    std::cout
            << (f(*static_cast<int *>(nullptr))
                ? "not null" : "null")
            << std::endl;

    int *pt = nullptr;
    int & rf = *pt;
    // error segmentation fault
    std::cout << rf;

    // error segmentation fault
    t(r);
    return 0;
}

bool f(int &r) { return &r != nullptr; }
void t(int &r) {
    std::cout << r;
}
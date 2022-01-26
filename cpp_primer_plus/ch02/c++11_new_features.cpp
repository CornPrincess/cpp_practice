//
// Created by 周天斌 on 11/13/21.
//
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << __cplusplus << std::endl;
    int nArr[5] = {1, 2, 3, 4, 5};
    for (int &x: nArr) {
        x *= 2;
    }
    for (int &x: nArr) {
        std::cout << x << std::endl;
    }
}

//
// Created by 周天斌 on 2021/11/11.
//
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << __cplusplus << std::endl;
#if __cplusplus == 201402L
    std::cout << "C++14" << std::endl;
#elif __cplusplus == 201103L
    std::cout << "C++11" << std::endl;
#else
    std::cout << "c/c++" << std::endl;
#endif
    return 0;
}

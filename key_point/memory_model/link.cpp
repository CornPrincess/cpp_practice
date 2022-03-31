//
// Created by 周天斌 on 2022/2/11.
//

#include <iostream>
#include <string>

int sum(int num);

int main() {
    for (int i = 1; i < 3; i++) {
        std::cout << sum(i) << std::endl;
    }
}

int sum(int num) {
    static int total;
    total += num;
    return total;
}
//
// Created by 周天斌 on 2022/1/20.
//

#include <iostream>

int main() {
    int nums[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        std::cout << nums[i] << std::endl;
    }
    for (int i: nums) {
        std::cout << i << std::endl;
    }
    return 0;
}
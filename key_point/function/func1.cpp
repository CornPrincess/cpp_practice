//
// Created by 周天斌 on 2022/2/8.
//

#include <iostream>
int[] test(); // error

int main() {
    test();
    return 0;
}

// error
int[] test() {
    int a[1] = {1, 2};
    return a;
}
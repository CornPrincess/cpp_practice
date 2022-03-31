//
// Created by 周天斌 on 2022/1/26.
//

#include <iostream>

int main() {
    int a = 7;
    const int *p = &a;
    //*p = 8; // error: read-only variable is not assignable

    int b = 9;
    int * const pt = &a;
    *pt = 8;
    pt = &b; // error variable 'pt' declared const here
    return 0;
}
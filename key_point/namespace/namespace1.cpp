//
// Created by 周天斌 on 2022/2/12.
//

#include <iostream>

namespace A {
    int a;
}

namespace B {
    int a;
}

int main() {
    using A::a;
    // using B::a; // error declaration conflict
    a = 1;
    return 0;
};
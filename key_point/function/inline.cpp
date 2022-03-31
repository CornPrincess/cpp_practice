//
// Created by 周天斌 on 2022/2/9.
//

#include <iostream>

// inline function definition
inline double square(double x) {
    return x * x;
}

int main() {
    using namespace std;
    double a, b;
    double c = 13.0;
    double d = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    cout << ", d squared = " << square(++d) << "\n";
    cout << "Now d = " << d << "\n";
    return 0;
}
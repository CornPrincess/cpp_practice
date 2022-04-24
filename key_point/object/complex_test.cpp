//
// Created by 周天斌 on 2022/4/6.
//
#include "complex.h"

using namespace std;

int main() {
    complex c1(2, 1);
    complex c2(4, 0);

    cout << c1 << endl;
    cout << c2 << endl;

    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 / 2 << endl;

    cout << conj(c1) << endl;
    cout << norm(c1) << endl;
    cout << polar(10, 4) << endl;

    cout << (c1 += c2) << endl;

    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    cout << +c2 << endl;
    cout << -c2 << endl;

    cout << (c2 - 2) << endl;
    cout << (5 + c2) << endl;

    return 0;
}

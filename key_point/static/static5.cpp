//
// Created by 周天斌 on 2022/2/14.
//

#include <iostream>

using namespace std;
class A {
public:
    static int x;
    int y;
    static void f() {
        // y++; Error invalid use of member 'y' in static member function
        x++;
        cout << "A static function, x = " << x << endl;
    }
};

int A::x;
int main() {
    A a;
    cout << "x = " << A::x << endl;
    cout << "x = " << a.x << endl;
    A::f();
    a.f();
    return 0;
}
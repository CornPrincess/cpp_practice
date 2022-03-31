//
// Created by 周天斌 on 2021/11/29.
//

#include <iostream>

double cube(double a);

double refcube(double &ra);
double testrefcube(const double &a);


//double pcube(double *pa);

//double constrefcube(const double &a);

int main() {
    using namespace std;
    double x = 3.0;
    double y = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    // error: read-only variable is not assignable
    // pcube(&x);
    // error: cannot assign to variable 'a' with const-qualified type 'const double &'
    // constrefcube(x);
    cout << testrefcube(y);
    cout << " = cube of " << y << endl;
    return 0;
}

double cube(double a) {
    a *= a * a;
    return a;
}

double refcube(double &ra) {
    ra *= ra * ra;
    return ra;
}

double testrefcube(const double &a) {
    // core 这里会生成临时变量，因此即是用的是引用传值，a的值还是不会改变，因为进行计算的是临时变量
    return a * a * a;
}
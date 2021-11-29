//
// Created by 周天斌 on 2021/11/29.
//

#include <iostream>

double cube(double a);

double refcube(double &ra);
double constrefcube(double &ra);


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
    cout << constrefcube(y);
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

// compiler error
//double pcube(const double *a) {
//    *a += 1;
//    return *a;
//}
//
//double constrefcube(const double &a) {
//    a += 1;
//    return a;
//}

double constrefcube(const double &a) {
    return a * a * a;
}
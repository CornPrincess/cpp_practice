//
// Created by 周天斌 on 2022/2/9.
//

#include <iostream>

// various notations, same signatures
const double *f1(const double ar[], int n);
const double *f2(const double [], int);
const double *f3(const double *, int);

int main() {
    using namespace std;
    double av[3] = {1.1, 2.2, 3.3};

    // define a pointer to a function, pre-C++11
    const double * (*p1)(const double * ar, int n) = f1;
    // C++11
    auto p2 = f2;
    cout << "The example of using pointers to functions:\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

    // define an array of pointers
    const double * (*pa[3])(const double * ar, int n) = {f1, f2, f3};
    auto pb = pa;
    cout  << "The example of using the array of function pointers:\n";
    for (int i = 0; i < 3; i++) {
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    }

    // define a pointer to an array of function pointers
    auto pc = &pa;
    const double * (*(*pd)[3])(const double * ar, int n) = &pa;
    cout << "The example of using a pointer to an array of functions:\n";
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    const double *pdd = (*pd)[1](av, 3);
    cout << pdd << ": " << *pdd << endl;
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    return 0;
}

const double *f1(const double *ar, int n) {
    return ar;
}

const double *f2(const double ar[], int n) {
    return ar + 1;
}

const double *f3(const double ar[], int n) {
    return ar + 2;
}
//
// Created by 周天斌 on 2022/2/10.
//

#include <iostream>

double refcube(const double &ra);

void swap(int &a, int &b);
void swap2(const int &a, const int &b);

using namespace std;
int main() {
    double side = 3.0;
    double *pd = &side;
    double &rd = side;
    long edge = 1L;
    double lens[4] = {2.0, 5.0, 1.0, 1.0};
    double c1 = refcube(side);
    double c2 = refcube(lens[2]);
    double c3 = refcube(rd);
    double c4 = refcube(*pd);
    double c5 = refcube(edge); // ra is temporary variable
    double c6 = refcube(7.0); // ra is temporary variable
    double c7 = refcube(side + 10); // ra is temporary variable

    double a = 1.1;
    double b = 2.2;
    cout << a << ", " << b << endl;
    swap(a, b);
    cout << a << ", " << b << endl;
    return 0;
}

double refcube(const double &ra) {
    return ra * ra * ra;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap2(const int &a, const int &b) {
    int temp = a;
    a = b;
    b = temp;
}
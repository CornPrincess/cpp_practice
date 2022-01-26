//
// Created by 周天斌 on 11/14/21.
//

#include <iostream>
int guess(double);

int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    // int convert to float
    float tree = 3;
    // double convert to int
    int guess(3.9832);
    // result not defined in C++
    int debt = 3.2E12;
    cout << "tree = " << tree <<endl;
    cout << "guess = " << guess <<endl;
    cout << "debt = " << debt <<endl;
    return 0;
}

int guess(double source) {
    return source;
}
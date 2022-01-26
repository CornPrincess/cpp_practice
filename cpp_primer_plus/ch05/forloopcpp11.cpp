//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>

int main() {
    using namespace std;
    double prices[5] = {1, 2, 3, 4, 5};
    cout << "Before write" << endl;
    // read loop
    for (double x : prices) {
        cout << x << endl;
    }
    // write loop
    for (double &x: prices) {
        x = x * 0.8;
    }
    cout << "After write" << endl;
    for (double x : prices) {
        cout << x << endl;
    }
    cout << "vector" << endl;
    // for vector etc
    for (int x: {3, 4, 5, 6, 7}) {
        cout << x << endl;
    }
}
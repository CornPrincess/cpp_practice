//
// Created by qwskyz on 2022/3/19.
//
#include <iostream>
using namespace std;

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    for (int n : a) {
        cout << n << " ";
    }
    cout << endl;
    a[10] = 11;
    cout << a[10] << endl;
    cout << a[12] << endl;
    return 0;
}
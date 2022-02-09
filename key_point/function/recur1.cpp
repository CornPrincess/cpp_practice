//
// Created by 周天斌 on 2022/2/9.
//

#include <iostream>

void countdown(int n);
void countdown2(int n);
using namespace std;

int main() {
    countdown(4);
    countdown2(4);
    return 0;
}

void countdown(int n) {
    cout << "Counting down ..." << n << " (n at " << &n << ")" << endl;
    if (n > 0) {
        countdown(n - 1);
    }
    cout << n << ": Kaboom!" << "(n at " << &n << ")" << endl;
}

void countdown2(int n) {
    if (n < 0) {
        return;
    }
    cout << "Counting down ..." << n << " (n at " << &n << ")" << endl;
    countdown2(n - 1);
    cout << n << ": Kaboom!" << "(n at " << &n << ")" << endl;
}
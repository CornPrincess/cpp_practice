//
// Created by 周天斌 on 2022/2/10.
//

#include <iostream>

void swapr(int &a, int &b);

void swapp(int *a, int *b);

void swapv(int a, int b);

int main() {
    using namespace std;
    int wallet1 = 1;
    int wallet2 = 2;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);    // pass variable
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2);  // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);    // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
    return 0;
}

void swapr(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapv(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
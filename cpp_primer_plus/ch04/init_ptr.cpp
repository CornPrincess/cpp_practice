//
// Created by 周天斌 on 2021/11/18.
//


#include <iostream>
int main() {
    using namespace std;
    int higgens = 5;
    int* pt = &higgens;

    cout << "Value of higgens = " << higgens
         << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
         << "; Value of pt = " << pt << endl;

    int* p_int;
    long* p_long;
    cout << "int point size: " << sizeof p_int << endl;
    cout << "long point size: " << sizeof p_long << endl;

    int* fellow;
    cout << "fellow address before init pointer: " << fellow << endl;
    // invalid
    // *fellow = 200;
    // cout << "fellow address after assign *fellow: " << fellow << endl;

    int* p_test;
    cout << "p_test address before init pointer: " << p_test << endl;
    // invalid  incompatible integer to pointer conversion assigning to 'int *' from 'unsigned int'
    // p_test = 0xB8000000;
    p_test = (int*) 0xB8000000;
    cout << "p_test address after assign pointer: " << p_test << endl;
    return 0;
}
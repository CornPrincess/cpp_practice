//
// Created by 周天斌 on 11/19/21.
//

#include <iostream>
int main() {
    using namespace std;
    int* pt;
    *pt = 7;
    cout << "==========before delete ============" << endl;
    // int value = 10; location = 0x7ffee341d948
    // todo  0x7ffee341d948 注意，这个地址是一个固定值，每次重新编译运行都是这个值，为什么
    cout << "int pt ";
    cout << "value = " << *pt << "; location = " << pt << endl;
    // location of pointer pt: 0x7ffee341d920
    cout << "location of pointer pt: " << &pt << endl;
    // ERROR malloc: *** error for object 0x7ffee186d948: pointer being freed was not allocated
    // delete pt;
    // ERROR
    // delete pt;
    cout << "==========after delete ============" << endl;
    // cout << "int ";
    // ERROR malloc: *** error for object 0x7ffee64d2948: pointer being freed was not allocated
    // cout << "value = " << *pt << "; location = " << pt << endl;
    // ERROR malloc: *** error for object 0x7ffee341d948: pointer being freed was not allocated
    // cout << "location of pointer pt: " << &pt << endl;

    cout << "===================================" << endl;

    int* pd = new int;
    *pd = 8;
    cout << "==========before delete ============" << endl;
    // int value = 10; location = 0x7ffee341d948
    cout << "int pd ";
    cout << "value = " << *pd << "; location = " << pd << endl;
    // location of pointer pd: 0x7ffee341d920
    cout << "location of pointer pd: " << &pd << endl;
    delete pd;
    // ERROR
    // delete pd;
    cout << "==========after delete ============" << endl;
    cout << "int ";
    // todo 以下两行代码不会报错，为什么使用new 就不会报错
    cout << "value = " << *pd << "; location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;
    cout << "===================================" << endl;

    int* ps;
    int test = 10;
    ps = &test;
    cout << "==========before delete ============" << endl;
    // int ps value = 10; location = 0x7ffee8d3a90c
    cout << "int ps ";
    cout << "value = " << *ps << "; location = " << ps << endl;
    // location of pointer ps: 0x7ffee8d3a910
    cout << "location of pointer ps: " << &ps << endl;
    // ERROR malloc: *** error for object 0x7ffee9c3890c: pointer being freed was not allocated
    // delete ps;
    cout << "==========after delete ============" << endl;
    // ERROR malloc: *** error for object 0x7ffee8d3a90c: pointer being freed was not allocated
    // cout << "int ps ";
    // cout << "value = " << *ps << "; location = " << ps << endl;
    // ERROR  malloc: *** error for object 0x7ffeed82790c: pointer being freed was not allocated
    // cout << "location of pointer ps: " << &ps << endl;
    cout << "===================================" << endl;

    int* a = new int;
    int* b = a;
    delete b;
    cout << "Delete use second pointer OK" << endl;
    // ERROR malloc: *** error for object 0x7fef8f405930: pointer being freed was not allocated
    // delete a;
}
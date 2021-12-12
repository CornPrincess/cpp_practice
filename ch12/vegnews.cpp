//
// Created by 周天斌 on 2021/12/12.
//

#include "stringbad.h"
#include <iostream>

using std::cout;
using std::endl;

// pass by reference
void callme1(StringBad &);

// pass by value
void callme2(StringBad);

int main() {
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << ", str address: " << (int *) headline1.getStr() << endl;
        cout << "headline2: " << headline2 << ", str address: " << (int *) headline2.getStr() << endl;
        cout << "sports: " << sports << ", str address: " << (int *) sports.getStr() << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << ", str address: " << (int *) headline1.getStr() << endl;
        // core 注意，这里函数按值传递，将会将headline中str的指针复制给一个临时变量，
        // core 而函数调用结束后会清除这个临时变量，因此会调用析构函数，delete str 的指针
        // core 当程序最终运行完后，要删除headline2 中 str 指针所指向的变量时就会报错，即释放内存两次
        callme2(headline2);
        cout << "headline2: " << headline2 << ", str address: " << (int *) headline2.getStr() << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << ", str address: " << (int *) sailor.getStr() << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << ", str address: " << (int *) knot.getStr() << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    return 0;
    /*
     * headline1: 0x7ff31d405930 (2 deleted)
     * headline2: 0x7ff31d405950
     * sports:    0x7ff31d405960 (3 deleted)
     * temp(copy constructor): 0x7ff31d405950 (1 deleted)
     * sailor:    0x7ff31d405960
     * knot:      0x7ff31d405930
     * "Celery Stalks at Midnight" object (address=0x7ff31d405930)deleted, 2 left
     * "Spinach Leaves Bowl for Dollars" object (address=0x7ff31d405960)deleted, 1 left
     * Spinach Leaves Bowl for Dollars" object (address=0x7ff31d405960)deleted, 0 left
     * vegnews(66746,0x10acd1e00) malloc: *** error for object 0x7f845a405960: pointer being freed was not allocated
     */
}

void callme1(StringBad &rsb) {
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"" << ", str address: " << (int *) rsb.getStr() << endl;
}

void callme2(StringBad sb) {
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"" << ", str address: " << (int *) sb.getStr() << endl;
}
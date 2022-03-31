//
// Created by 周天斌 on 11/20/21.
//

#include <iostream>
int main() {
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    // here ara two ways to get the address of an array
    double* pw = wages;
    short* ps = &stacks[0];

    // with array element
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stacks[0]
         << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stacks = " << *stacks
         << ", *(stacks + 1) = " << *(stacks + 1) << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*ps = " << *ps
         << ", *(ps + 1) = " << *(ps + 1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";
    cout << sizeof(ps) << " = size of ps pointer\n";

    // &stacks = 0x7ffee3f7c916
    cout << "&stacks = " << &stacks << endl;
    // &stacks[0] = 0x7ffee3f7c916
    cout << "&stacks[0] = " << &stacks[0] << endl;

    return 0;
}
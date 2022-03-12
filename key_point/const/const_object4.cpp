//
// Created by 周天斌 on 2022/3/12.
//

#include <iostream>

using namespace std;

class Alice {
private:
    int a;
public:
    Alice(int a): a(a) {}
    int get_a() {return a;}
    const int* get_const_ptr() {return &a;}
    int* get_ptr() {return &a;}
};

int main() {
    Alice alice(1);
    int a1 = alice.get_a(); // ok
    cout << a1 << endl;
    const int a2 = alice.get_a(); // ok
    cout << a2 << endl;

    // error cannot initialize a variable of type 'int *' with an rvalue of type 'const int *'
    // int* b1 = alice.get_const_ptr();
    const int* b2 = alice.get_const_ptr(); // ok
    cout << *b2 << endl; // ok
    // *b2 = 3; // error read-only variable is not assignable

    *(alice.get_ptr()) = 3;
    cout << alice.get_a() << endl; // 3
    return 0;
}
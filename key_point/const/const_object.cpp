//
// Created by qwskyz on 2022/3/12.
//

#include <iostream>
using namespace std;

class R {
public:
    R(int r1, int r2) {
        a = r1;
        b = r2;
    }

    void print();
    void print() const;

private:
    int a;
    int b;
};

void R::print() {
    cout << "normal print" << endl;
    cout << a << ", " << b << endl;
}

void R::print() const {
    cout << "const print" << endl;
    cout << a << ", " << b << endl;
}

int main() {
    R a(5, 3);
    a.print();
    const R b(6 ,6);
    b.print();
    return 0;
}
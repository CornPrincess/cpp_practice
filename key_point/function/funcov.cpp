//
// Created by 周天斌 on 2022/2/10.
//

#include <iostream>

using namespace std;

void show1(int & a) {
    cout << "reference" << endl;
}
void show1(const int & a) {
    cout << "reference const" << endl;
}

void show2(int * a) {
    cout << "pointer" << endl;
}
void show2(const int * a) {
    cout << "pointer const" << endl;
}

void show3(int a) {
    cout << "value" << endl;
}
// Error redefinition of show3
//void show3(const int a) {
//    cout << "value const" << endl;
//}

int main() {
    const int rf = 1;
    int rf2 = 2;
    show1(rf);
    show1(rf2);

    int * pt = &rf2;
    const int * pt2 = &rf2;
    show2(pt);
    show2(pt2);
    return 0;
}


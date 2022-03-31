//
// Created by 周天斌 on 2022/1/5.
//

#include <iostream>

using std::cout;
using std::endl;

void change(const int *pt, int n);

void change2(int *pt, int n);

int main() {
    int pop1 = 38383;
    const int pop2 = 2000;
    int pop3 = 3000;

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    change(&pop1, -103);
    change(&pop2, -103);
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    cout << endl;
    cout << "pop1, pop3: " << pop1 << ", " << pop3 << endl;
    change2(&pop1, -103);
    change2(&pop3, -103);
    cout << "pop1, pop3: " << pop1 << ", " << pop3 << endl;
    return 0;
}

void change(const int *pt, int n) {
    int *pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}

void change2(int *pt, int n) {
    int *pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}
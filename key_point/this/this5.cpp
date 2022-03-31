//
// Created by 周天斌 on 2022/2/15.
//

#include<iostream>
using namespace std;

class Dog {
public:
    Dog() :m_age(10) {}
    Dog& f(Dog gp) {
        m_age += gp.m_age;
        return *this;
    }
    int m_age;
};

void func1() {
    Dog g1;
    cout << "func1 before: " << g1.m_age << endl;
    Dog g2;
    g2.f(g1).f(g2).f(g2);
    cout << "func1 after: " << g2.m_age << endl;
}

void func2() {
    Dog g1;
    cout << "func2 before: " << g1.m_age << endl;
    Dog g2;
    g2.f(g1);
    g2.f(g2);
    g2.f(g2);
    cout << "func2 after: " << g2.m_age << endl;
}

int main() {
    func1();
    func2();
    return 0;
}

//
// Created by 周天斌 on 2022/3/12.
//

#include <iostream>

using namespace std;

class A {
private:
    int m_a;
public:
    A() {}
    explicit A(int a) {
        m_a = a;
    }
    void show() const {
        cout << m_a << endl;
    }
    // core 转化函数
    operator int() const {
        return m_a;
    }

    operator double() const {
        return (double) m_a;
    }
};

int main() {
    A a(1);
    a.show();
    A a2 = (A)2;
    a2.show();

    int c1 = a;
    double d1 = a;
    cout << c1 << endl;
    cout << d1 << endl;
    return 0;
}


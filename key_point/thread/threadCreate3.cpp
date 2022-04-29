//
// Created by qwskyz on 22-4-28.
//

#include <iostream>
#include <thread>

using namespace std;

class A {
public:
    A(int num):m_num(num) {
        cout << "A created" << "thread: " << std::this_thread::get_id() << endl;
    }
    A(const A& a):m_num(a.m_num) {
        cout << "A copy" << "thread: " << std::this_thread::get_id() << endl;
    }
    ~A() {
        cout << "A destroy" << "thread: " << std::this_thread::get_id() << endl;
    }
    int get_num() const {
        return m_num;
    }
    void set_num(int num) {
        m_num = num;
    }
private:
    int m_num;
};

// core has to use const
void func1(const A& a) {
    cout << "func1 " << a.get_num() << endl;
}

// core can not use const
void func2(A& a) {
    a.set_num(20);
    cout << "func2 " << a.get_num() << endl;
}

int main() {
    A a(2);
    std::thread t1(func1, a);
    t1.join();
    cout << "t1.join, a " << a.get_num() << endl;

    // core std::ref
    std::thread t2(func2, std::ref(a));
    t2.join();
    cout << "t2.join, a " << a.get_num() << endl;
    return 0;
}
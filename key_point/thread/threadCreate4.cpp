//
// Created by qwskyz on 22-4-28.
//

#include <iostream>
#include <thread>

using namespace std;

void func(unique_ptr<int> ptr) {
    ptr.get();
    cout << "func" << endl;
}

class A {
public:
    A(int num):m_num(num) {
        cout << "A created " << "thread: " << std::this_thread::get_id() << endl;
    }
    A(const A& a):m_num(a.m_num) {
        cout << "A copy " << "thread: " << std::this_thread::get_id() << endl;
    }
    ~A() {
        cout << "A destroy " << "thread: " << std::this_thread::get_id() << endl;
    }
    int get_num() const {
        return m_num;
    }
    void set_num(int num) {
        m_num = num;
    }

    void thread_work(int num) {
        cout << "thread work " << num << endl;
    }
private:
    int m_num;
};

int main() {
    unique_ptr<int> p1(new int(100));
    std::thread t1(func, std::move(p1));
    t1.join();
    // core not use detach, because used std::move
    // t1.detach();

    A a(2);
    // std::thread t2(&A::thread_work, a, 10);
    // core &a has the same effect with std::ref(a), can not use detach
    // std::thread t2(&A::thread_work, &a, 10);
    std::thread t2(&A::thread_work, std::ref(a), 10);
    t2.join();
    return 0;
}
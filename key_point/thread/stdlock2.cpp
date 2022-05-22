//
// Created by qwskyz on 22-4-29.
//
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class A {
public:
    void func1() {
        std::lock(m_mutex1, m_mutex2);
        std::lock_guard<std::mutex> guard1(m_mutex1, std::adopt_lock);
        std::lock_guard<std::mutex> guard2(m_mutex2, std::adopt_lock);
        cout << "func1 " << "thread: " << this_thread::get_id() << endl;
    }

    void func2() {
        std::lock(m_mutex2, m_mutex1);
        std::lock_guard<std::mutex> guard1(m_mutex1, std::adopt_lock);
        std::lock_guard<std::mutex> guard2(m_mutex2, std::adopt_lock);
        cout << "func2 " << "thread: " << this_thread::get_id() << endl;
    }
private:
    std::mutex m_mutex1;
    std::mutex m_mutex2;
};

int main() {
    A a;
    std::thread t1(&A::func1, &a);
    std::thread t2(&A::func2, &a);
    t1.join();
    t2.join();
    cout << "main end" << endl;
    return 0;
}
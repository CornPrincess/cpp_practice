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
        m_mutex1.lock();
        m_mutex2.lock();
        cout << "func1 " << "thread: " << this_thread::get_id() << endl;
        m_mutex2.unlock();
        m_mutex1.unlock();
    }

    void func2() {
        m_mutex2.lock();
        m_mutex1.lock();
        cout << "func2 " << "thread: " << this_thread::get_id() << endl;
        m_mutex1.unlock();
        m_mutex2.unlock();
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
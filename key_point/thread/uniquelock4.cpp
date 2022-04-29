//
// Created by qwskyz on 22-4-29.
//
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class A {
public:
    unique_lock<mutex> get_unique_lock() {
        return unique_lock<mutex>(m_mutex1);
    }

    void func1() {
        cout << "enter func1" << endl;
        // core this is ok, will call move constructor
        std::unique_lock<std::mutex> uniqueLock = get_unique_lock();
        cout << "func1 " << "thread: " << this_thread::get_id() << endl;
    }

    void func2() {
        cout << "enter func2" << endl;
        // core try to lock
        std::unique_lock<std::mutex> uniqueLock = get_unique_lock();
        // this is ok
        // std::unique_lock<std::mutex> uniqueLock2(std::move(uniqueLock));
        std::mutex *p = uniqueLock.release();
        cout << "func2 get lock" << endl;
        cout << "func2 " << "thread: " << this_thread::get_id() << endl;
        // core after release, has to unlock
        p->unlock();
    }

private:
    std::mutex m_mutex1;
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
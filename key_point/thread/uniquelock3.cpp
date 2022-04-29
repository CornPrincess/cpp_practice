//
// Created by qwskyz on 22-4-29.
//
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

class A {
public:
    void func1() {
        cout << "enter func1" << endl;
        std::unique_lock<std::mutex> uniqueLock(m_mutex1);
        cout << "func1 get lock and start to sleep" << endl;
        std::chrono::milliseconds slice(5000);
        std::this_thread::sleep_for(slice);
        cout << "func1 " << "thread: " << this_thread::get_id() << endl;
    }

    void func2() {
        cout << "enter func2" << endl;
        // core try to lock
        std::unique_lock<std::mutex> uniqueLock(m_mutex1, std::defer_lock);
        uniqueLock.try_lock();
        if (uniqueLock.owns_lock()) {
            cout << "func2 get lock" << endl;
            cout << "func2 " << "thread: " << this_thread::get_id() << endl;
        } else {
            cout << "Bad luck, func2 not  get lock" << endl;
        }
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
//
// Created by qwskyz on 22-4-29.
//

#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <list>

class A {
public:
    void produce() {
        for (int i = 0; i < 100; i++) {
            std::unique_lock<std::mutex> ulock(m_mutex);
            list.push_back(i);
            std::cout << "thread: " << std::this_thread::get_id() << ", produce: " << i << std::endl;
            m_con.notify_one();
            // m_con.notify_all();
        }
    }

    void consume() {
        while (true) {
            std::unique_lock<std::mutex> ulock(m_mutex);
            // if lambda return false, wait will block
            m_con.wait(ulock, [this]{
                return !list.empty();
            });
            int num = list.front();
            list.pop_front();
            ulock.unlock();
            std::cout << "thread: " << std::this_thread::get_id() << ", consume: " << num << std::endl;
        }
    }


private:
    std::list<int> list;
    std::mutex m_mutex;
    std::condition_variable m_con;
};

int main() {
    A a;
    std::thread t1(&A::produce, &a);
    std::thread t2(&A::consume, &a);
    std::thread t3(&A::consume, &a);
    t1.join();
    t2.join();
    t3.join();

    std::cout << "main end" << std::endl;
    return 0;
}
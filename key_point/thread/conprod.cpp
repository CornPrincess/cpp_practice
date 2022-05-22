//
// Created by qwskyz on 22-4-29.
//

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

#define MAX_CAPACITY  10

class Buffer {
public:
    Buffer(): m_con_index(0), m_pro_index(0), size(0) {}
    void produce(int num) {
        // 1. lock
        std::unique_lock<std::mutex> ulock(m_mutex);
        // 2. wait if full
        not_full.wait(ulock, [this]() {
            return size != MAX_CAPACITY;
        });
        // 3. produce
        buf[m_pro_index] = num;
        std::cout << "thread " << std::this_thread::get_id() << " produced " << num << "\n";
        // 4. update index and size
        m_pro_index = (m_pro_index + 1) % MAX_CAPACITY;
        size++;
        // 5. unlock
        ulock.unlock();
        // 6. notify
        not_empty.notify_one();
    }

    int consume() {
        // 1. lock
        std::unique_lock<std::mutex> ulock(m_mutex);

        // 2. wait if empty
        not_empty.wait(ulock, [this]() {
            return size != 0;
        });
        // 3. consume
        int num = buf[m_con_index];
        std::cout << "thread " << std::this_thread::get_id() << " consumed " << num << "\n";
        // 4. update index and size
        m_con_index = (m_con_index + 1) % MAX_CAPACITY;
        size--;
        // 5. unlock
        ulock.unlock();
        // 6. notify
        not_full.notify_one();
        return num;
    }

private:
    int m_pro_index;
    int m_con_index;
    int size;
    int buf[MAX_CAPACITY];

    std::mutex m_mutex;
    std::condition_variable not_full;
    std::condition_variable not_empty;
};

void produceInt(Buffer &buf) {
    for (int i = 1; i <= 100; i++) {
        buf.produce(i);
    }
    std::cout << "============== thread: " << std::this_thread::get_id() << " end =================" << std::endl;
}

void consumeInt(Buffer &buf) {
    while (true) {
        buf.consume();
    }
}

int main() {
    Buffer buffer;
    std::thread p1(produceInt, std::ref(buffer));
    std::thread p2(produceInt, std::ref(buffer));
    std::thread p3(produceInt, std::ref(buffer));

    std::thread c1(consumeInt, std::ref(buffer));
    std::thread c2(consumeInt, std::ref(buffer));

    p1.join();
    p2.join();
    p3.join();
    c1.join();
    c2.join();

    std::cout << "main end" << std::endl;
    return 0;
}
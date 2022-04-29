//
// Created by qwskyz on 22-4-28.
//
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

void func() {
    cout << "func" << endl;
};

class A {
public:
    int m_i;
    A(int a) :m_i(a) { cout << "构造函数执行" << this << ", thread id:" << std::this_thread::get_id() << endl; }
    A(const A &a) :m_i(a.m_i) { cout << "拷贝构造函数执行" << this << ", thread id:" << std::this_thread::get_id() << endl;}
    A(A &&a) :m_i(std::move(a.m_i)) { cout << "move构造函数执行" << this << ", thread id:" << std::this_thread::get_id() << endl;}
    ~A() { cout << "析构函数执行" << this << ", thread id:" << std::this_thread::get_id() << endl;}

    //子线程入口
    void operator()(int num) {
        cout << "子线程thread_work执行" << num << ", " << this << ", thread id:" << std::this_thread::get_id() << endl;
    }
};

class B {
public:

    B(int num): m_num(num) {
        cout << "B created" << endl;
    }
    B(const B& b): m_num(b.m_num) {
        cout << "B copy" << endl;
    }
    ~B() {
        cout << "B destroy" << endl;
    }
    void operator()() {
        cout << "B func1 " << m_num << endl;
        // sleep(3);
        cout << "B func2 " << m_num << endl;
        cout << "B func3 " << m_num << endl;
    }
private:
    // core can not use reference, it use num in main, when thead detach and main exit, it will occur error
    // int& m_num;
    int m_num;
};

int main() {
    cout << "================ Create thread with function ================" << endl;
    std::thread t1(func);
    t1.join();

    cout << "================ Create thread with Object1 ================" << endl;
    A a(10);
    // 注意这个构造函数的调用方法
    cout << "main thread: " << std::this_thread::get_id() << endl;
    std::thread t2(a, 15); // copy 2
    // std::thread t2(std::move(a), 16);// move 2
    // std::thread t2(std::ref(a), 17);
    // t2.join();
    // t2.join();
    t2.join();

    cout << "================ Create thread with Object2 ================" << endl;
    int num = 6;
    B b(num);
    std::thread t3(b);
    // core thead will copy object, so detach is ok, but if B contains some pointer of reference class member, it will has problem
    // t3.detach();
    t3.join();

    cout << "================ Create thread with lambda ================" << endl;
    auto lamb = [] {
        cout << "lambda func" << endl;
    };
    std::thread t4(lamb);
    t4.join();
    return 0;
}

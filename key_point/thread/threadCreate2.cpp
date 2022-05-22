//
// Created by qwskyz on 22-4-28.
//

#include <iostream>
#include <thread>
#include <string>

using namespace std;
// core reference will copy value, i and main num has different address
// core but pointer will not copy, buf and main buf has same address value, if detach can not pass pointer
// void func1(const int & i, char * buf) {
void func1(const int & i, const std::string& buf) {
    cout << "func 1" << endl;
    cout << i << endl;
    cout << buf << endl;
}

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
private:
    int m_num;
};

void func2(int num, const A& a) {
    cout << "func 2" << endl;
    cout << &a << " a.num: " << a.get_num() << "son thread: " << this_thread::get_id() << endl;
}

int main() {
    // 1. pass temporary object as parameter
    cout << "================ test thread detach and func parameter has pointer =====================" << endl;
    int num = 1;
    int& rnum = num;
    char buf[] = "this is my buf";
    cout << "main thread: " << std::this_thread::get_id() << endl;

    // core not stable, buf will be deleted when main thread end, and at this time buf has not been copied to thread func1
    // std::thread t1(func1, rnum, buf);
    // core can use this way to confirm buf be copied before it delete
    std::thread t1(func1, rnum, std::string(buf));
    // join is ok
     t1.join();
    //t1.detach();

    cout << "================ test thread detach and func parameter has object =====================" << endl;
    int i = 1;
    int j = 2;
    // core 如果使用以下代码,A对象是在子线程中构造的，detach时就会有风险
    // std::thread t2(func2, i, j);
    // if join has no problem, it can create object normally
    // t2.join();
    // core if detach, can not confirm create object
    // core use follow code, the constructor will be called
    // core 对象A是在主线程中构造，可以保证没有风险
    std::thread t2(func2, i, A(j));
    t2.join();
    //t2.detach();
    return 0;
}
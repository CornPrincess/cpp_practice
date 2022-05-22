//
// Created by qwskyz on 22-5-1.
//

//一般格式
#include<iostream>
#include<thread>
#include<mutex>
#include<future>

using namespace std;

int mythread(int mypar) {
    cout << mypar << endl;
    cout << "mythread2 start, " << "threadid = " << std::this_thread::get_id() << endl;

    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    cout << "mythread2 end, " << "threadid = " << std::this_thread::get_id() << endl;

    return 5;
}

int main() {
    cout << "main, " << "threadid = " << std::this_thread::get_id() << endl;
    // 我们把函数mythread通过packaged_task包装起来
    std::packaged_task<int(int)> mypt(mythread);
    // 线程直接开始执行,第二个参数作为线程入口函数的参数
    // core use std::ref
    std::thread t1(std::ref(mypt), 1);
    cout << "main created thread t1" << endl;
    t1.join();
    // std::future对象里包含有线程入口函数的返回结果，这里result保存mythread返回的结果
    std::future<int> result = mypt.get_future();

    cout << result.get() << endl;
    cout << "I love China!" << endl;

    return 0;
}
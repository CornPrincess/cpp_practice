//
// Created by qwskyz on 22-5-1.
//
#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<list>
#include<mutex>
#include<future>
using namespace std;

class A {
public:
    int mythread2(int mypar) {
        cout << mypar << endl;
        cout << "mythread2 start" << "threadid = " << std::this_thread::get_id() << endl;

        std::chrono::milliseconds dura(5000);
        std::this_thread::sleep_for(dura);

        cout << "mythread2 end" << "threadid = " << std::this_thread::get_id() << endl;

        return 5;
    }
};

// 线程入口函数
int mythread()  {
    cout << "mythread start, "<< "threadid = " <<std::this_thread::get_id()<<endl;
    // 定一个5秒的时间
    std::chrono::milliseconds dura(5000);
    // 休息一定时常
    std::this_thread::sleep_for(dura);

    cout << "mythread end, " << "threadid = " << std::this_thread::get_id() << endl;

    return 5;
}

int main() {
    A a;
    int tmppar = 12;
    cout <<"main " << "threadid = " << std::this_thread::get_id() << endl;
    // 创建一个线程并开始执行,绑定关系,流程并不卡在这里
    // std::future<int> result = std::async(mythread);
    // 第二参数是对象引用，才能保证线程里面是同一个对象
    // std::future<int> result = std::async(std::launch::deferred,&A::mythread2,&a,tmppar);
    std::future<int> result = std::async(std::launch::async, &A::mythread2, &a, tmppar);
    cout << "continue....." << endl;

    int def;
    def = 0;
    // 卡在这里等待mythread()执行完毕，拿到结果；只能调用一次；//打印线程id
    // cout << result.get()<< endl;
    // result.wait();//等待线程返回，本身并不返回结果
    cout << "I love China!" << endl;
    return 0;
}
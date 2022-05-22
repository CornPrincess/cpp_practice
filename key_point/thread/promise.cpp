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

void mythread(std::promise<int>&tmpp, int calc) {
    // 做一系列复杂的操作
    calc++;
    calc *= 10;
    cout << "enter mythread and start to sleep " << this_thread::get_id() << endl;
    // 做其他运算，比如整整花费了5秒钟
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);

    int result = calc;
    // 结果保存到了tmpp这个对象中
    tmpp.set_value(result);
    cout << "leave mythread " << this_thread::get_id() << endl;
}

void mythread2(std::future<int> &tmpf) {
    cout << "enter mythread2 and start to get " << this_thread::get_id() << endl;
    auto result = tmpf.get();
    cout <<"mythread result = " << result<<endl;
    cout << "leave mythread2 " << this_thread::get_id() << endl;
}

int main() {
    cout << "main start " << endl;
    // 声明一个std::promise对象myprom,保存的值类型为int;
    std::promise<int> myprom;
    std::thread t1(mythread,std::ref(myprom),180);
    t1.join();

    // 获取结果值
    // promise与future绑定，用于获取线程返回值
    std::future<int> fu1 = myprom.get_future();

    std::thread t2(mythread2,std::ref(fu1));
    // 等mythread2执行完毕
    t2.join();

    cout << "I love China!"  << endl;

    return 0;
}
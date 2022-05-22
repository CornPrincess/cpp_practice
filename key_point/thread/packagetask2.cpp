//
// Created by qwskyz on 22-5-1.
// lamdba表达式作为可调用对象、采用容器

#include<iostream>
#include<thread>
#include<vector>
#include<list>
#include<mutex>
#include<future>

using namespace std;

vector < std::packaged_task<int(int)>> mytasks;

int main() {
    cout << "main, " << "threadid = " << std::this_thread::get_id() << endl;

    std::packaged_task<int(int)> mypt([](int mypar) {
        cout << mypar << endl;
        cout << "mythread2 start, " << "threadid = " << std::this_thread::get_id() << endl;
        std::chrono::milliseconds dura(5000);
        std::this_thread::sleep_for(dura);
        cout << "mythread2 end, " << "threadid = " << std::this_thread::get_id() << endl;
        return 5;
    });


    // core move
    mytasks.push_back(std::move(mypt));

    std::packaged_task<int(int)> mypt2;
    auto iter = mytasks.begin();
    mypt2 = std::move(*iter); // 移动语义
    mytasks.erase(iter); // 删除一个元素，迭代器已经失效了，所以后续代码不可以再使用iter;

    // core 直接调用，相当于函数调用, not create thread
    mypt2(105);
    std::future<int> result = mypt2.get_future();
    cout << result.get() << endl;

    return 0;
}
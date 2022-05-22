//
// Created by qwskyz on 22-4-29.
//
#include<iostream>
#include<thread>
#include<list>
// core bug
// double free or corruption (fasttop)
// Process finished with exit code 134 (interrupted by signal 6: SIGABRT)
using namespace std;

// 准备用成员函数作为线程函数的方法写线程
class A {
public:
    // 把收到的消息入到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000;i++) {
            cout << "inMsgRecvQueue()执行，插入一个元素"<< i<<endl;
            // 假设这个数字i就是收到的命令，直接弄到消息队列里边来；
            msgRecvQueue.push_back(i);
        }
    }

    // 把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            if (!msgRecvQueue.empty()) {
                // 消息不为空
                // 返回第一个元素，但不检查元素是否存在
                int command = msgRecvQueue.front();
                msgRecvQueue.pop_front();//移除第一个元素。但不返回；
                // 这里就考虑处理数据
            }
            else {
                // 消息队列为空
                cout << "outMsgRecvQueue()执行，但目前消息队列中为空！" << i << endl;
            }
        }
        cout <<"end!" << endl;
    }

private:
    // 容器（消息队列），代表玩家发送过来的命令。
    std::list<int> msgRecvQueue;
};

int main() {
    A myobja;

    // 第二个参数，引用，才能保证线程里用的是同一个对象
    std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myOutMsgObj.join();
    myInMsgObj.join();

    cout << "主线程执行！" << endl;

    return 0;
}
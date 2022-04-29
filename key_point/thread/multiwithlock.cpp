//
// Created by qwskyz on 22-4-29.
//
#include<iostream>
#include<thread>
#include<list>
#include <mutex>

using namespace std;

// 准备用成员函数作为线程函数的方法写线程
class A {
public:
    // 把收到的消息入到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 100000;i++) {
            cout << "inMsgRecvQueue()执行，插入一个元素"<< i<<endl;
            // 假设这个数字i就是收到的命令，直接弄到消息队列里边来；
            m_mutex.lock();
            msgRecvQueue.push_back(i);
            m_mutex.unlock();
        }
    }

    int outMsg() {
        m_mutex.lock();
        if (!msgRecvQueue.empty()) {
            // 消息不为空
            // 返回第一个元素，但不检查元素是否存在
            int command = msgRecvQueue.front();
            msgRecvQueue.pop_front();//移除第一个元素。但不返回；
            m_mutex.unlock();
            return command;
        }
        m_mutex.unlock();
        return -1;
    }

    // 把数据从消息队列取出的线程
    void outMsgRecvQueue() {
        for (int i = 0; i < 100000; i++) {
            int num = outMsg();
            if (num > 0) {
                cout << "outMsgRecvQueue()执行，data: " << num << endl;
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
    std::mutex m_mutex;
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
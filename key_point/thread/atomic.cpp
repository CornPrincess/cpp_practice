//
// Created by qwskyz on 22-5-1.
//

#include<iostream>
#include<thread>
#include<future>

using namespace std;

// 我们封装了一个类型为int的对象，像操作一个int类型变量一样来操作这个g_mycont
std::atomic<int> g_mycont(0);

void mythread() {
    for (int i = 0; i < 1000000; i++)
    {
        g_mycont++;//对应的操作是个原子操作（不会被打断）
        // g_mycont += 1;
        // g_mycont = g_mycont + 1;  //结果不对，不是原子操作
    }
}
int main() {
    thread myobj(mythread);
    thread myobj2(mythread);

    myobj.join();
    myobj2.join();

    cout << "两个线程执行完毕，最终的g_mycont的结果是:" << g_mycont <<endl;

    return 0;
}
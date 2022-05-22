//
// Created by qwskyz on 22-4-29.
//
#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton *local_instance;
    Singleton() {
        cout << "构造" << endl;
    };
    ~Singleton() {
        cout << "析构" << endl;
    }

public:
    static Singleton *getInstance() {
        static Singleton local_s;
        return &local_s;
    }
};


int main() {
    cout << "单例模式访问第一次前" << endl;
    Singleton * s = Singleton::getInstance();
    cout << "单例模式访问第一次后" << endl;
    cout << "单例模式访问第二次前" << endl;
    Singleton * s2 = Singleton::getInstance();
    cout << "单例模式访问第二次后" << endl;
    return 0;
}
//
// Created by qwskyz on 22-4-29.
// core c11 new feature: magic static
#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton inst;
        return inst;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // 其他数据函数
    // ...
    ~Singleton() {
        std::cout << "destroy" << std::endl;
    }

    void method() {
        std::cout << "method" << std::endl;
    }
private:
    Singleton() {
        std::cout << "created" << std::endl;
    }
    // 其他数据成员
    // ...
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    s1.method();
    s2.method();
    return 0;
}
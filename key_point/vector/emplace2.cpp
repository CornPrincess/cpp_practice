//
// Created by qwskyz on 22-5-4.
//
#include <vector>
#include <iostream>
using namespace std;

class testDemo {
public:
    testDemo(int num):num(num){
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }
private:
    int num;
};

int main() {
    //testDemo t1(2);
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    //demo1.emplace_back(t1);
    //demo1.emplace_back(move(t1));
    demo1.emplace_back(2);

    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    //demo2.push_back(t1);
    //demo1.push_back(move(t1));
    demo1.push_back(2);
}
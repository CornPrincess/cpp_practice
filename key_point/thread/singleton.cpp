//
// Created by qwskyz on 22-4-29.
//
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex resource;

class singleton {
public:
    static singleton* get_instance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> guard(resource);
            if (instance == nullptr) {
                instance = new singleton();
                static cgar c;
            }
        }
        return instance;
    }

    ~singleton() {
        cout << "singleton destroy " << endl;
    }
    void print() {
        cout << "func" << endl;
    }
private:
    singleton() {
        cout << "singleton create " << endl;
    }
    static singleton * instance;

    class cgar {
    public:
        cgar() {
            cout << "cgar create " << endl;
        }
        ~cgar() {
            cout << "cgar destroy " << endl;
            if (singleton::instance) {
                cout << "start to destroy singleton" << endl;
                delete singleton::instance;
                singleton::instance = nullptr;
            }
        }
    };
};

singleton* singleton::instance = nullptr;

void method() {
    cout << "method start" << endl;
    singleton* p = singleton::get_instance();
    cout << "method end" << endl;
}

int main() {
    std::thread t1(method);
    std::thread t2(method);
    t1.join();
    t2.join();
    return 0;
}
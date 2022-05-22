//
// Created by qwskyz on 22-4-29.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

std::once_flag g_flag;

class singleton {
public:
    static singleton* get_instance() {
        std::call_once(g_flag, init);
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

    static void init() {
        cout << "=========== call once start ===============" << endl;
        cout << "start to sleep " << this_thread::get_id() << endl;
        std::chrono::milliseconds slice(5000);
        std::this_thread::sleep_for(slice);
        if (instance == nullptr) {
            instance = new singleton();
            static cgar c;
        }
        cout << "=========== call once end ===============" << endl;
    }

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
    // core other thread will be blocked by callonce function
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
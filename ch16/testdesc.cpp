//
// Created by 周天斌 on 2022/1/5.
//

#include <iostream>

using namespace std;

class T {
private:
    int num;
public:
    T(int a = 0) : num(a) {}

    ~T() { cout << "destructor " << num << endl; }

    void show() const { cout << num << endl; }
};

int main() {
    {
        T t1 = T(1);
        T *t2 = new T(2);
        t1.show();
        t2->show();
//        delete t2;
    }
    return 0;
}
//
// Created by 周天斌 on 2022/2/9.
//

#include <iostream>

using namespace ::std;
class Demo {
public:
    void show();
};

inline void Demo::show() {
    cout << "class inline function." << endl;
}

int main() {
    Demo d;
    d.show();
    return 0;
}
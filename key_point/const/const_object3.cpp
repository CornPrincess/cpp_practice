//
// Created by 周天斌 on 2022/3/12.
//

#include <iostream>

using namespace std;

class Alice {
private:
    int a;
public:
    Alice(int a): a(a) {}
    void show() const;
};

void Alice::show() const {
    //  error: cannot assign to non-static data member within const member function 'show'
    // this->a = 1;
    cout << "hello Alice" << endl;
}

int main() {
    const Alice a(1);
    a.show();
    return 0;
}
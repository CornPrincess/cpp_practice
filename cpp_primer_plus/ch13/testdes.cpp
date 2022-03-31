//
// Created by 周天斌 on 2021/12/26.
//
#include <iostream>

using namespace std;

class TBase {
public:
    TBase() {}

    virtual ~TBase() {
        cout << "Base Destructor" << endl;
    }

    void show() {
        cout << "base show" << endl;
    }
};

class TDerived : public TBase {
public:
    TDerived() {}

    virtual ~TDerived() {
        cout << "Derived Destructor" << endl;
    }

    void show() {
        cout << "derived show" << endl;
    }
};

int main() {
    {
        TBase* bp = new TBase();
        delete bp;
    }
    return 0;
}


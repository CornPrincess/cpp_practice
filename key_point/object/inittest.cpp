//
// Created by qwskyz on 22-4-25.
//

#include <iostream>

using namespace std;
class Test1 {
public:
    Test1()  {
        cout << "Construct Test1" << endl ;
    }

    Test1(const Test1& t1) {
        cout << "Copy constructor for Test1" << endl ;
        this->a = t1.a ;
    }

    Test1& operator = (const Test1& t1) {
        cout << "assignment for Test1" << endl ;
        this->a = t1.a ;
        return *this;
    }
private:
    int a ;
};

class Test2 {
public:
    Test1 test1 ;
    Test2(Test1 &t1) {
        test1 = t1 ;
    }
};

class Test3 {
public:
    Test1 test1 ;
    Test3(Test1 &t1) : test1(t1){
    }
};

int main() {
    Test1 test1;
    // Construct Test1
    Test2 test2(test1);
    // Construct Test1
    // assignment for Test1
    Test3 test3(test1);
    return 0;
}
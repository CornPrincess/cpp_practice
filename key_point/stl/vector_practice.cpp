//
// Created by qwskyz on 22-5-14.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Person {
private:
    string m_name;
    int m_age;
public:
    Person() = default;
    Person(const string &mName, int mAge) : m_name(mName), m_age(mAge) {}

    const string &getMName() const {
        return m_name;
    }

    void setMName(const string &mName) {
        m_name = mName;
    }

    int getMAge() const {
        return m_age;
    }

    void setMAge(int mAge) {
        m_age = mAge;
    }
};

void print(int n) {
    cout << n;
}

void myPrint(vector<int> & vec) {
    for (const  int &n : vec) {
        cout << n << " ";
    }
    cout << endl;
}

void vector_buildin() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    // method 1
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
    }
    cout << endl;

    // method2
    auto iter = vec.begin();
    while (iter != vec.end()) {
        cout << *iter;
        iter++;
    }
    cout << endl;

    // method3
    for (auto it = vec.begin(); it < vec.end(); it++) {
        cout << *it;
    }
    cout << endl;

    // method4
    for (int i : vec) {
        cout << i;
    }
    cout << endl;

    // method5
    for_each(vec.begin(), vec.end(), print);
    cout << endl;
}

void vector_class() {
    vector<Person> vec;
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);
    vec.push_back(p1);
    vec.push_back(p2);
    vec.push_back(p3);
    vec.push_back(p4);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[0].getMName() << " " << vec[0].getMAge() << endl;
    }
    cout << endl;

    for (const Person& p : vec) {
        cout << p.getMName() << " " << p.getMAge() << endl;
    }
    cout << endl;

    for (auto it = vec.begin(); it < vec.end(); it++) {
        cout << it->getMName() << " " << it->getMAge() << endl;
    }
    cout << endl;
}

void construct() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    myPrint(v1);

    vector<int> v2(v1);
    myPrint(v2);

    vector<int> v3(10, 100);
    myPrint(v3);

    vector<int> v4(v3.begin(), v3.end());
    cout << v1.capacity() << endl;
    myPrint(v4);
}

void reserve() {
    vector<int> vec;
    int *p = nullptr;
    int cnt = 0;
    vec.reserve(100000);
    for (int i = 0; i < 100000; i++) {
        vec.push_back(i);
        if (p != &vec[0]) {
            p = &vec[0];
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    vector_buildin();
    vector_class();
    construct();
    reserve();
    return 0;
}
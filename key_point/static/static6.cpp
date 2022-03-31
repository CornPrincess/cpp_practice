//
// Created by 周天斌 on 2022/2/16.
//

#include <iostream>

using namespace std;

class Person {
public:
    Person() {};
    Person(char *name, int age);
    void show();
    static int getTotal();
private:
    static int m_total;
    char *m_name;
    int m_age;
};

Person::Person(char *name, int age) : m_name(name), m_age(age) {
    m_total++;
}

void Person::show() {
    cout << m_name << "的年龄是" << m_age << ", 总人数是" << m_total << endl;
}

int Person::getTotal() {
    return m_total;
}

// 一定要先初始化
int Person::m_total = 0;

int main() {
    Person *p1 = new Person("Alice", 18);
    Person *p2 = new Person("Bob", 18);
    p1->show();
    p2->show();
    int total1 = Person::getTotal();
    int total2 = p1->getTotal();
    cout << "total1 = " << total1 << ", total2 = " << total2 << endl;
    return 0;
}
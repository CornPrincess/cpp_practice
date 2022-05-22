//
// Created by qwskyz on 22-5-15.
//

#include <set>
#include <iostream>

using namespace std;

class Person {
private:
    string m_id;
    string m_name;
    int m_age;
public:
    Person() = default;
    Person(string id, string name, int age): m_id(id), m_name(name), m_age(age) {}

    bool operator<(const Person& p) const {
        if (m_id != p.m_id) {
            return m_id < p.m_id;
        } else {
            return m_age < p.m_age;
        }
    }
    const string& getMId() const{
        return m_id;
    }
    const string& getMName() const {
        return m_name;
    }
    int getMAge() const {
        return m_age;
    }
};

class MyPersonCmp {
public:
    bool operator()(const Person& p1, const Person& p2) {
        if (p1.getMId() == p2.getMId() && p1.getMName() == p2.getMName()) {
            return false;
        }
        if (p1.getMId() != p2.getMId()) {
            return p1.getMId() < p2.getMId();
        } else {
            return  p1.getMAge() < p2.getMAge();
        }
    }
};

struct Node {
    int id;
    int value;
    Node() {}
    Node(int _id, int _value): id(_id), value(_value) {}
    bool operator<(const Node& n) const {
        if (id == n.id) {
            return false;
        }
        if (value != n.value) {
            return value > n.value;
        } else {
            return id < n.id;
        }
    }
};

bool cmp(const Node& n1, const Node& n2) {
    if (n1.id == n2.id) {
        return false;
    }
    if (n1.value != n2.value) {
        return n1.value < n2.value;
    } else {
        return n1.id < n2.id;
    }
}

void sort1() {
    Person p1("1", "A1", 10);
    Person p2("1", "A2", 10);
    Person p3("1", "B", 5);
    Person p4("3", "C", 10);
    Person p5("4", "D", 10);

    set<Person> s;
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->getMId() << " " << it->getMName() << " " << it->getMAge() << endl;
    }
    cout << "====================================" << endl;
}

void sort2() {
    Node n1(1,2);
    Node n2(2,3);
    Node n3(2,4);
    Node n4(3,4);
    Node n5(4,4);
    set<Node> s;
    s.insert(n1);
    s.insert(n2);
    s.insert(n3);
    s.insert(Node(1, 3));
    s.insert(n4);
    s.insert(n5);

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->id << " " << it->value << endl;
    }
    cout << "====================================" << endl;
}

void sort3() {
    set<Person, MyPersonCmp> s;
    s.insert(Person("1", "A", 9));
    s.insert(Person("1", "A", 10));
    s.insert(Person("2", "B", 10));
    s.insert(Person("2", "C", 5));
    s.insert(Person("3", "D", 8));

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->getMId() << " " << it->getMName() << " " << it->getMAge() << endl;
    }
    cout << "====================================" << endl;
}

void sort4() {
    set<Node, decltype(&cmp)> s(cmp);
    s.insert(Node(1, 1));
    s.insert(Node(1, 2));
    s.insert(Node(2, 8));
    s.insert(Node(3, 6));
    s.insert(Node(4, 4));

    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->id << " " << it->value << endl;
    }
    cout << "====================================" << endl;
}

void sort5() {
    auto cmp = [](const Node& n1, const Node& n2) {
        if (n1.id == n2.id) {
            return n1.value < n2.value;
        }
        return n1.id < n2.id;
    };
    set<Node, decltype(cmp)> s(cmp);
    s.insert(Node(1, 1));
    s.insert(Node(1, 2));
    s.insert(Node(2, 8));
    s.insert(Node(3, 6));
    s.insert(Node(4, 4));

    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->id << " " << it->value << endl;
    }
    cout << "====================================" << endl;
}

int main() {
    sort1();
    sort2();
    sort3();
    sort4();
    sort5();
    return 0;
}


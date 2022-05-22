//
// Created by qwskyz on 22-5-15.
//

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    Person() = default;
    Person(string _name, int _age): name(_name), age(_age) {}

    bool operator==(const Person& p) const {
        return name == p.name && age == p.age;
    }
};

size_t person_hash(const Person& p) {
    return hash<string>()(p.name) ^ hash<int>()(p.age);
}

class Hash {
public:
    size_t operator()(const Person& p) const {
        return hash<string>()(p.name) ^ hash<int>()(p.age);
    }
};

class Equal {
public:
    bool operator()(const Person& p1, const Person& p2) const {
        return p1.name == p2.name && p1.age == p2.age;
    }
};

void sort1() {
    unordered_map<Person, int, decltype(&person_hash)> m(10, person_hash);
    m.insert({Person("A", 1), 1});
    m.insert({Person("A", 1), 2});
    m.insert({Person("A", 2), 2});
    m.insert({Person("B", 3), 3});
    cout << "size " << m.size() << endl;
    cout << "bucket count " << m.bucket_count() << endl;
    cout << "max_size " << m.max_size() << endl;
    cout << "max_bucket_count " << m.max_bucket_count() << endl;
    for (const auto& it : m) {
        cout << "(" << it.first.name << " " << it.first.age << ") " << it.second << endl;
    }
    cout << "=================================" << endl;
}

void sort2() {
    unordered_map<Person, int, Hash, Equal> m;
    m.insert({Person("A", 1), 1});
    m.insert({Person("A", 1), 2});
    m.insert({Person("A", 2), 2});
    m.insert({Person("B", 3), 3});
    cout << "size " << m.size() << endl;
    cout << "bucket count " << m.bucket_count() << endl;
    cout << "max_size " << m.max_size() << endl;
    cout << "max_bucket_count " << m.max_bucket_count() << endl;
    for (const auto& it : m) {
        cout << "(" << it.first.name << " " << it.first.age << ") " << it.second << endl;
    }
    cout << "=================================" << endl;
}

int main() {
    sort1();
    sort2();
    return 0;
}
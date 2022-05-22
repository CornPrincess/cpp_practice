//
// Created by qwskyz on 22-5-15.
//

#include <map>
#include <iostream>
#include <string>

using namespace std;

void printMap(map<int, int>& m) {
    for (auto it: m) {
        cout << it.first << " " << it.second << endl;
    }
}

void printMap2(map<int, int, greater<int>>& m) {
    for (auto it: m) {
        cout << it.first << " " << it.second << endl;
    }
}

void construct() {
    map<int, int> m;
    m.insert({8, 2});
    m.insert(pair<int, int>(1, 3));
    m.insert({2,3});
    m.insert({2,4});
    m.insert({3,4});
    printMap(m);

    map<int, int> m2 = m;
    map<int, int> m3;
    m3 = m;
    printMap(m2);
    printMap(m3);


    cout << "====================================" << endl;
}

void sort1() {
    map<int, int> m1;
    m1.insert({1,2});
    m1.insert({2,3});
    m1.insert({3,4});
    m1.insert({4,5});
    printMap(m1);

    map<int, int, greater<int>> m2;
    m2.insert({1,2});
    m2.insert({2,3});
    m2.insert({3,4});
    m2.insert({4,5});
    printMap2(m2);
    cout << "====================================" << endl;
}

class CmyByStrLen {
public:
    bool operator()(const string& s1, const string& s2) {
        return s1.length() < s2.length();
    }
};

void sort2() {
    map<string, int, CmyByStrLen> m;
    m.insert({"1111", 1});
    m.insert({"111", 1});
    m.insert({"11", 1});
    m.insert({"0000000", 1});

    for (const auto& it: m) {
        cout << it.first << " " << it.second << endl;
    }
    cout << "====================================" << endl;
}

struct Node {
    int id;
    int value;
    Node() = default;
    Node(int _id, int _value): id(_id), value(_value) {}
    bool operator<(const Node& n) const {
        if (id != n.id) {
            return id < n.id;
        } else {
            return value < n.value;
        }
    }
};

class CmpById {
public:
    bool operator()(const Node& n1, const Node& n2) {
        if (n1.id == n2.id) {
            return  false;
        } else {
            return n1.id < n2.id;
        }
    }
};

void sort3() {
    map<Node, int> m;
    m.insert({Node(1, 2), 1});
    m.insert({Node(1, 3), 2});
    m.insert({Node(2, 4), 3});
    m.insert({Node(3, 5), 4});
    for (auto it: m) {
        cout << "(" << it.first.id << " " << it.first.value << ") " << it.second << endl;
    }
    cout << "====================================" << endl;
}

void sort4() {
    map<Node, int, CmpById> m;
    m.insert({Node(1, 2), 1});
    m.insert({Node(1, 3), 2});
    m.insert({Node(2, 4), 3});
    m.insert({Node(3, 5), 4});
    for (auto it: m) {
        cout << "(" << it.first.id << " " << it.first.value << ") " << it.second << endl;
    }
    cout << "====================================" << endl;
}

void sort5() {
    auto cmp = [](const Node& n1, const Node& n2) {
        if (n1.id == n2.id) {
            return  false;
        } else {
            return n1.id > n2.id;
        }
    };
    map<Node, int, decltype(cmp)> m(cmp);
    m.insert({Node(1, 2), 1});
    m.insert({Node(1, 3), 2});
    m.insert({Node(2, 4), 3});
    m.insert({Node(3, 5), 4});
    for (auto it: m) {
        cout << "(" << it.first.id << " " << it.first.value << ") " << it.second << endl;
    }
    cout << "====================================" << endl;
}

int main() {
    construct();
    sort1();
    sort2();
    sort3();
    sort4();
    sort5();
    return 0;
}
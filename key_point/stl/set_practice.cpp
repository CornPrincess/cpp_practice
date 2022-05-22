//
// Created by qwskyz on 22-5-14.
//

#include <set>
#include <iostream>

using namespace std;

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void printSet(const set<int>& set) {
    for (auto it = set.begin(); it != set.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printSet2(const set<int, MyCompare>& set) {
    for (auto it = set.begin(); it != set.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void construct() {
    set<int> set1;
    set1.insert(1);
    set1.insert(22);
    set1.insert(45);
    set1.insert(1);
    set1.insert(94);
    set1.insert(3);
    printSet(set1);

    set<int> set2(set1);
    printSet(set2);

    set<int> s3;
    s3 = set2;
    s3.insert(1);
    printSet(s3);
    cout << s3.size() << endl;
}

void erase() {
    set<int> set1;
    set1.insert(1);
    set1.insert(22);
    set1.insert(45);
    set1.insert(1);
    set1.insert(94);
    set1.insert(3);
    printSet(set1);

    auto a = set1.erase(set1.begin());
    printSet(set1);
    cout << *a << endl;

    int b = set1.erase(10);
    cout << b <<endl;
    printSet(set1);
    cout << set1.size() << endl;

    set1.clear();
    cout << set1.size() << endl;
    printSet(set1);
}

void insert() {
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    cout << *ret.first << " " << ret.second << endl;
    pair<set<int>::iterator, bool> ret2 = s.insert(10);
    cout << *ret2.first << " " << ret2.second << endl;
    cout << endl;
}

void multiset_test() {
    multiset<int> mset;
    auto ret = mset.insert(10);
    cout << *ret << endl;
    auto ret2 = mset.insert(10);
    cout << *ret2 << endl;
    auto ret3 = mset.insert(5);
    cout << *ret3 << endl;
    auto ret4 = mset.insert(50);
    cout << *ret4 << endl;

    for (auto it = mset.begin(); it != mset.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void sort_test() {
    set<int> set1;
    set1.insert(1);
    set1.insert(22);
    set1.insert(45);
    set1.insert(1);
    set1.insert(94);
    set1.insert(3);
    printSet(set1);

    set<int, MyCompare> set2;
    set2.insert(1);
    set2.insert(22);
    set2.insert(45);
    set2.insert(1);
    set2.insert(94);
    set2.insert(3);
    printSet2(set2);
}

int main() {
    construct();
    erase();
    insert();
    multiset_test();
    sort_test();
    return 0;
}
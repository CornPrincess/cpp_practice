//
// Created by 周天斌 on 2022/2/11.
//

#include <iostream>

template<typename T>
void Swap(T &a, T &b);

struct job {
    int size;
};

// explict specialization
template<>
void Swap<job>(job &j1, job &j2);

int main() {
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int Swapper:\n";
    Swap(i, j);      // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job alice = {1};
    job bob = {2};
    cout << "Before job Swapping:\n";
    cout << "alice's size: " << alice.size << endl;
    cout << "bob's size: " << bob.size << endl;
    Swap(alice, bob);  // uses void Swap(job &, job &)
    cout << "After job Swapping:\n";
    cout << "alice's size: " << alice.size << endl;
    cout << "bob's size: " << bob.size << endl;
    return 0;
}

template<typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<>
void Swap<job>(job &j1, job &j2) {
    int temp = j1.size;
    j1.size = j2.size;
    j2.size = temp;
}
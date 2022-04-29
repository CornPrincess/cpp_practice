//
// Created by qwskyz on 22-4-28.
//

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

vector<int> gv = {1, 2, 3};

void func(int num) {
    cout << "thread: " << this_thread::get_id() << "num: " << num << ", gcv: " << gv[0] <<  gv[1] << gv[2] <<endl;
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(func, i);
    }
    for (auto & thread : threads) {
        thread.join();
    }
    cout << "main stop" << endl;
    return 0;
}
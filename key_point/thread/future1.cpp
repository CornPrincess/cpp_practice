//
// Created by qwskyz on 22-5-1.
//

#include <future>
#include <iostream>
#include <chrono>

using namespace std;

int method() {
    cout << "method start, thread: " << this_thread::get_id() << endl;
    chrono::milliseconds slice(5000);
    cout << "method start to sleep" << endl;
    this_thread::sleep_for(slice);
    cout << "method sleep end" << endl;
    return 5;
}

int main() {
    cout << "main start, thread: " << this_thread::get_id() << endl;
    std::future<int> fu = std::async(method);
    cout << "main created future and continue" << endl;
    int result = fu.get();
    cout << "future get result: " << result << endl;
    return 0;
}
//
// Created by qwskyz on 22-4-28.
//

#include <thread>
#include <iostream>
#include <unistd.h>

void hello() {
    std::cout << "Hello world" << std::endl;
}

int main() {
    std::thread t(hello);
    //t.join();
    // sleep(10);
    //t.detach();
    return 0;
}

//
// Created by 周天斌 on 2022/1/26.
// compile with support.cpp

#include <iostream>
using namespace std;

// external variable, warming defined
double warming = 0.3;
int a = 1;

// function prototype
void update(double dt);
void local();

int main() {
    // using global variable
    cout << "Global warming is " << warming << " degrees.\n";
    // call function to change warming
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    // call function with local warming
    local();
    cout << "Global warming is " << warming << " degrees.\n";
    return 0;
}
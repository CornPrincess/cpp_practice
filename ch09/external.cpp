//
// Created by 周天斌 on 2021/12/6.
//

#include <iostream>

using namespace std;

// external variable
// warming defined  one definition rule
double warming = 0.3;

// function prototype, not optional
void update(double dt);

void local();

int main()                  // use global variable
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);            // call function to change warming
    cout << "Global warming is " << warming << " degress.\n";
    local();                // call function with local warming
    cout << "Global warming is " << warming << " degrees.\n";
    return 0;
}
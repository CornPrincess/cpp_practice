//
// Created by 周天斌 on 2022/1/26.
// to be compiled with twofile2.cpp

#include <iostream>

// external variable definition
int tom = 3;
// external variable definition
int dick = 30;
// static, internal linkage
static int harry = 300;

// function prototype
void remote_access();

int main() {
    using namespace std;
    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
    cout << "main() reports the following values:\n";
    cout << tom << " = tom, " << dick << " = dick, " << harry << " = harry\n";
    remote_access();
    return 0;
}
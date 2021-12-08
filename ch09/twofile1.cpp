//
// Created by 周天斌 on 2021/12/6.
//

#include <iostream>     // to be compiled with twofile2.cpp
int tom = 3;            // external variable definition
int dick = 30;          // external variable definition
static int harry = 300; // static, internal linkage

// function prototype
void remote_access();

int main()
{
    using namespace std;
    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    cout << "main() reports the following values:\n";
    cout << tom << " = tom, " << dick << " = dick, ";
    cout << harry << " = harry\n";
    remote_access();
    return 0;
}
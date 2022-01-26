//
// Created by 周天斌 on 2022/1/26.
//

#include <iostream>

// tom defined elsewhere
extern int tom;
// overrides external dick
static int dick = 10;
// external variable definition,
// no conflict with twofile1 harry
int harry = 200;

void remote_access() {
    using namespace std;
    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
    cout << "remote_access() reports the following values:\n";
    cout << tom << " = tom, " << dick << " = dick, " << harry << " = harry\n";
}
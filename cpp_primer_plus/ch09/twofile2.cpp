//
// Created by 周天斌 on 2021/12/6.
//

#include <iostream>
extern int tom;         // tom defined elsewhere
static int dick = 10;   // overrides external dick
int harry = 200;        // external variable definition,
// no confilict with twofile1 harry

void remote_access()
{
    using namespace std;
    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    cout << "remote_access() reports the following values:\n";
    cout << tom << " = tom, " << dick << " = dick, ";
    cout << harry << " = harry\n";
}
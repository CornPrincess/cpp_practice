//
// Created by 周天斌 on 2021/12/23.
//

#include <iostream>
#include <bitset>
#include <stdio.h>

using namespace std;

int main() {
    short s = 65;
    int i = s;
    char ch = s;
    cout << "positive upcast: " << endl;
    cout << "sizeof int: " << sizeof i << ", i = " << i << ", hex i = " << hex << i << endl;
    cout << "sizeof char: " << sizeof ch << ", ch = " << ch << ", hex i = " << hex << i << endl;

    // 00000000 00000000 10000000 00000000
    int i2 = 32768;
    short s2 = i2;
    char ch2 = i2;
    cout << "positive downcast: " << endl;
    cout << "sizeof int: " << sizeof i2 << ", i2 = " << i2 << ", hex i2 = " << hex << i2 << endl;
    cout << "sizeof short: " << sizeof s2 << ", s2 = " << s2 << ", hex s2 = " << hex << s2 << endl;
    cout << "sizeof char: " << sizeof ch << ", ch2 = " << ch2 << ", (int) ch2 = " << (int) ch2 << endl;

    short s3 = -1;
    int i3 = s3;
    cout << "negative upcast: " << endl;
    // ffffffff
    cout << "sizeof int: " << sizeof i3 << ", i3 = " << i3 << ", hex i3 = " << hex << i3 << endl;
    // ffff
    cout << "sizeof short: " << sizeof s3 << ", s3 = " << s2 << ", hex s3 = " << hex << s3 << endl;

    cout << "int to float" << endl;
    int i4 = 37;
    int i5 = -7;
    cout << dec;
    cout << "binary format of " << i4 << " is: " << bitset<sizeof(int) * 8>(i4) << endl;
    cout << "binary format of " << i5 << " is: " << bitset<sizeof(int) * 8>(i5) << endl;
    float f1 = i4;
    float f2 = *(float *) &i4;
    cout << "binary format of " << f1 << " is: " << bitset<sizeof(float) * 8>(f1) << endl;
    cout << "binary format of " << f2 << " is: " << bitset<sizeof(float) * 8>(f2) << endl;

    cout << "float to int" << endl;
    float f3 = 7.0;
    short s4 = * (short *) &f3;
    cout << "binary format of " << f3 << " is: " << bitset<sizeof(float) * 8>(f3) << endl;
    cout << "binary format of " << s4 << " is: " << bitset<sizeof(short) * 8>(s4) << endl;
    printf("f3=%x", f3);
    printf("s4=%d", s4);

}
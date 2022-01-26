//
// Created by 周天斌 on 2021/12/14.
//

#include <iostream>

int main() {
    using std::cout;
    using std::endl;
    char * str = 0;
    char * str1 = nullptr;
    char * str2 = new char[10];
    cout << "str address: " << (int *) str << endl;
    cout << "str1 address: " << (int *) str1 << endl;
    cout << "str2 address: " << (int *) str2 << endl;
    /* before delete output
     * str address: 0x0
     * str1 address: 0x0
     * str2 address: 0x7fb2f94059e0
     */
    delete[] str;
    delete[] str1;
    delete[] str2;
    cout << "str address: " << (int *) str << endl;
    cout << "str1 address: " << (int *) str1 << endl;
    cout << "str2 address: " << (int *) str2 << endl;
    /* after delete output
     * str address: 0x0
     * str1 address: 0x0
     * str2 address: 0x7fb2f94059e0
     */
}
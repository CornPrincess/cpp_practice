//
// Created by 周天斌 on 11/14/21.
//

#include <iostream>
int main()
{
    using namespace std;
    bool is_ready = false;
    bool is_ok = true;
    cout << "bool to int: " << endl;
    cout << "is_ready: " << is_ready << endl;
    cout << "is_ok: " << is_ok << endl;
    int a = is_ready;
    int b = is_ok;
    cout << "int to bool: " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    bool test_true = -100;
    bool test_false = 0;
    cout << "test bool: " << endl;
    cout << "test_true: " << test_true << endl;
    cout << "test_false: " << test_false << endl;
    return 0;
}

//
// Created by qwskyz on 22-5-14.
//

#include <string>
#include <iostream>

using namespace std;

using namespace std;

void construct() {
    string s1;

    const char* str = "hello";
    string s2(str);
    cout << s2 << endl;

    string s3(s2);
    cout << s3 << endl;

    string s4(5, 'h');
    cout << s4 << endl;
}

void assign() {
    string s1;
    s1 = "hello";
    cout << s1 << endl;

    string s2 = s1;
    cout << s2 << endl;

    string s3;
    char c = 'a';
    s3 = c;
    cout << s3 << endl;

    string s4;
    s4.assign("hello");
    cout << s4 << endl;

    string s5;
    s5.assign("hello", 3);
    cout << s5 << endl;

    string s6;
    s6.assign(s1);
    cout << s6 << endl;

    string s7;
    s7.assign(5, 'a');
    cout << s7 << endl;
}

int main() {
    construct();
    assign();
}
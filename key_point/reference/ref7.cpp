//
// Created by 周天斌 on 2022/2/10.
//

#include <iostream>
#include <string>

using namespace std;

string version1(const string &s1, const string &s2);

const string &version2(string &s1, const string &s2); // has side effect
const string &version3(string &s1, const string &s2); // bad design

int main() {
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    // core 为什么程序运行到这里没有崩溃
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    return 0;
}

string version1(const string &s1, const string &s2) {
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

// has side effect
const string &version2(string &s1, const string &s2) {
    s1 = s2 + s1 + s2;
    return s1;
}

// bad design
const string &version3(string &s1, const string &s2) {
    string temp;
    temp = s2 + s1 + s2;
    // unsafe to return reference to local variable
    return temp;
}

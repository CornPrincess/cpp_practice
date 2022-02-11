//
// Created by 周天斌 on 2022/1/5.
//

#include <iostream>
#include <string>

int main() {
    using namespace std;
    string one("Lottery Winner!");  // ctor #1
    cout << one << endl;            // overload <<
    string two(20, '$');            // ctor #2
    cout << two << endl;
    string three(one);              // ctor #3
    cout << three << endl;
    one += " Oops!";                // overloaded +=
    cout << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';
    string four;
    four = two + three;
    cout << four << endl;
    char alls[] = "All's well that ends well";
    string five(alls,20);           // ctor #5
    cout << five << "!\n";
    string six(alls+6, alls+10);    // ctor #6
    cout << six << ", ";
    string seven(&five[6], &five[10]);// ctor #6 again
    cout << seven << "...\n";
    string eight(four, 7, 16);      // ctor #7
    cout << eight << " in motion!" << endl;
    string nine = {'h', 'e', 'l', 'l', 'o'};
    cout << nine << endl;
    return 0;

}
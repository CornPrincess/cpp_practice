//
// Created by 周天斌 on 11/14/21.
//

#include <iostream>
int main()
{
    using namespace std;
    char ch = 'M';      // assign ASCII code for M to ch
    int i = ch;         // store same code in an int
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;        // change character code in ch
    i = ch;             // save new character code in i
    // cout 把 ch 显示为 M， 把 i 显示为 77， 值的类型将引导cout 选择如何显示值——这是智能对象（smart object）的另一个例子
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // using the cout.put() member function to display a char
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);

    // using cout.put() to display a char constant
    cout.put('!');
    cout << endl;

    // test cin int
    int j;
    cout << "Test cin int, please enter an integer: ";
    cin >> j;
    cout << "The integer is: " << j;
    cout << endl << "Done" << endl;
    return 0;
}

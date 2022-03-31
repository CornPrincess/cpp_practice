//
// Created by 周天斌 on 11/14/21.
//

#include <iostream>
#include <cstring> // strlen

int main() {
    using namespace std;
    char dog[8] = {'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'};
    char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'};
    // invalid
    // char test[2] = {'f', 'a', 't', '\0'};
    cout << "dog: " << dog <<endl;
    cout << "cat: " << cat <<endl;

    char bird[11] = "Mr bird";
    // invalid
    // char fish[2] = "Bubble";
    cout << "bird: " << bird << endl;

    // concat
    // 任何两个由空白（空格，制表符和换行符）分割的字符串常量都将自动拼接成一个
    cout << "I'd give" " a great.\n";
    cout << "I'd give a great.\n";
    cout << "I'd give"
            " a great.\n";
    cout << "=====================================" << endl;

    const int Size = 9;
    char name1[Size];               // empty array
    char name2[Size] = "C++owboy";  // initialized array
    // NOTE: some implementations may require the static keyword
    // to initialize the array name2

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';                // set to null character

    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    cout << "Now, the string length of my name: ";
    cout << strlen(name2) << endl;
    char test[12];
    cout << "Test empty array size of: " << sizeof test << endl;
    cout << "Test char size of: " << sizeof (char) << endl;
    return 0;
}
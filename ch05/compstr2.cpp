//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
#include <string>       // string class

int main() {
    using namespace std;
    string word = "?ate";
    for (char ch = 'a'; word != "mate"; ch++) {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word;
}
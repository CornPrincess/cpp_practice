//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
#include <string>

int main() {
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    cout << word.size() << endl;
    // display letters in reverse order
    for (int i = word.size() - 1; i >= 0; i--) {
        cout << word[i];
    }
    cout << "\nBye.\n";
    return 0;
}
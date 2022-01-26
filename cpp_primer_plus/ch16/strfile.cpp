//
// Created by 周天斌 on 2022/1/5.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    using namespace std;
    ifstream fin;
    fin.open("./tobuy.txt");
    if (fin.is_open()) {
        string item;
        int count = 0;
        getline(fin, item, ':');
        while (fin) // while input is good
        {
            ++count;
            cout << count << ": " << item << endl;
            getline(fin, item, ':');
        }
        cout << "Done\n";
        fin.close();
        return 0;
    } else {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
}
//
// Created by 周天斌 on 11/20/21.
//

#include <iostream>
#include <cstring>      // or string.h
using namespace std;
char* getname(void); // function prototype

int main() {
    // create pointer but no storage
    char* name;

    name = getname();   // assign address of string to name
    cout << name << " at " << (int *) name << "\n";
    delete [] name;     // memory freed

    name = getname();   // reuse freed memory
    cout << name << " at " << (int *) name << "\n";
    delete [] name;     // memory freed again
    return 0;
}

char* getname() {
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char* pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);

    return pn;
}
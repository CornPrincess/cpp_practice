//
// Created by 周天斌 on 2021/11/18.
//

#include <iostream>
int main() {
    using namespace std;

    int updates = 6;
    int * p_updates;
    p_updates = &updates;

    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", p_updates = " << *p_updates << endl;

    // express address two ways
    cout << "Address: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    cout << "Now p_updates = " << *p_updates << endl;
    return 0;
}
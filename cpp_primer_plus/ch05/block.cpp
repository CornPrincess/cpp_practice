//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>

int main() {
    using namespace std;
    cout << "The Amazing Account will sum and average ";
    cout << "five numbers for you.\n";
    cout << "Please enter five values:\n";
    double number;
    double sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        // blocks starts here
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }                                   // blocks ends here
    cout << "Five exquisite choices indeed! ";
    cout << "They sum to " << sum << endl;
    cout << "and average to " << sum / 5 << ".\n";
    cout << "The Amazing Account bids you adieu!\n";
    return 0;
}
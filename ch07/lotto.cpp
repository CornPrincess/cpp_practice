//
// Created by 周天斌 on 11/25/21.
//

#include <iostream>

// Note: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);

int main() {
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";
    while ((cin >> total >> choices) && choices <= total) {
        cout << "You have one chance in ";
        cout << probability(total, choices);    // compute the odds
        cout << " of winning.\n";
        cout << "New two numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}

// the following function calculates the probability of picking picks
// number correctly from numbers choices
long double probability(unsigned numbers, unsigned picks) {
    long double result = 1.0;   // here comes some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
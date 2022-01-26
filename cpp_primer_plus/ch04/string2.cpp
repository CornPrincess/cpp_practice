//
// Created by 周天斌 on 2021/11/15.
//

#include <iostream>
#include <cstring> // strlen

int main() {
    using namespace std;
    int cards[4] = {1, 2, 3, 4};
    int hands[4];
    // not allowed
    // cards = {5, 6, 7, 8};
    // not allowed
    // hands = cards;
    float hotelTips[5] = {1.1, 2.2};
    for (int i = 0; i < 5; i++) {
        cout << hotelTips[i] << endl;
    }
    cout << "==================" << endl;
    short things[] = {1, 2, 3, 4};
    int num_elements = sizeof things / sizeof(short);
    cout << num_elements;
    // not allowed
    // long plifts = {23, 0.9};
}
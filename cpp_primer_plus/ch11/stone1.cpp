//
// Created by 周天斌 on 2021/12/12.
//

#include <iostream>
#include "stonewt1.h"

int main() {
    using std::cout;
    Stonewt poppins(9, 2.8);     // 9 stone, 2.8 pounds
    double p_wt = poppins;       // implicit conversion
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n";
    cout << "Poppins: " << (int) poppins << " pounds.\n";
    // explict type case
    long test_long = (long) poppins;
    cout << "Convert to long => ";
    cout << "Poppins: " << test_long << " pounds.\n";
    return 0;
}
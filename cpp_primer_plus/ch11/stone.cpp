//
// Created by 周天斌 on 2021/12/12.
//

#include "stonewt.h"
#include <iostream>

using std::cout;

void display(const Stonewt &st, int n);

int main() {
    // use constructor to initialize
    Stonewt incognito = 275;
    //  same as Stonewt wolfe = 258.7
    Stonewt wolfe(258.7);
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();
    incognito = 276.8;          // uses constructor for conversion
    // core 使用 Stonewt(double n) 构造函数，这里325转化为double
    taft = 325;                 // same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinner, the President weighed ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighted even more.\n";
    // core 这里编译器查找构造函数 Stonewt(int n) 但是不符合要求，因此使用 Stonewt(double n)
    display(422, 2);
    cout << "No stone left unearned\n";

    // an explicit conversion
    Stonewt test_explict = (Stonewt)12;
    // old form for explicit typecast
    Stonewt test_explict2 = Stonewt(12);
    test_explict.show_stn();
    test_explict2.show_stn();
}

void display(const Stonewt &st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
}
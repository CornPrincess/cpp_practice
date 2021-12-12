//
// Created by 周天斌 on 2021/12/12.
//

#include "stonewt.h"
#include <iostream>
using std::cout;

Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
}

Stonewt::Stonewt(double lbs) {
    stone = int(lbs) / Lbs_per_stn;    // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int lbs) {
    stone = pounds = pds_left = 1;
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::~Stonewt() {

}

// show weight in stones
void Stonewt::show_stn() const {
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const {
    cout << pounds << " pounds\n";
}
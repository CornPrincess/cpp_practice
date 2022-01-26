//
// Created by 周天斌 on 2021/12/12.
//

#ifndef CPP_PRACTICE_STONEWT1_H
#define CPP_PRACTICE_STONEWT1_H
class Stonewt
{
    private:
        enum {Lbs_per_stn = 14};        // pounds per stone
        int stone;                      // whole stones
        double pds_left;                // fractional pounds
        double pounds;                  // entire weight in pounds
    public:
        Stonewt(double lbs);            // construct from double pounds
        Stonewt(int stn, double lbs);   // construct from stone, lbs
        Stonewt();                      // default constructor
        ~Stonewt();
        void show_lbs() const;          // show weight in pounds format
        void show_stn() const;          // show weight in stone format
        // conversion functions
        operator int() const;
        operator double() const;
        explicit operator long() const;
};
#endif //CPP_PRACTICE_STONEWT1_H

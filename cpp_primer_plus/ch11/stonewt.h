//
// Created by 周天斌 on 2021/12/12.
//

#ifndef CPP_PRACTICE_STONEWT_H
#define CPP_PRACTICE_STONEWT_H

class Stonewt {
private:
    static const int Lbs_per_stn = 14;
//    enum {Lbs_per_stn=14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt();
    Stonewt(int stn, double lbs);
    Stonewt(double lbs);
    explicit Stonewt(int lbs);
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
};

#endif //CPP_PRACTICE_STONEWT_H

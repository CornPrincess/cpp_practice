//
// Created by 周天斌 on 2021/12/9.
//

#ifndef CPP_PRACTICE_STOCK10_H
#define CPP_PRACTICE_STOCK10_H

#include <string>

class Stock {
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {
        total_val = shares * share_val;
    }

public:
    // default constructor
    Stock();
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    // noisy destructor
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif //CPP_PRACTICE_STOCK10_H

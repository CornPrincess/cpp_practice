//
// Created by 周天斌 on 2021/12/9.
//

#ifndef CPP_PRACTICE_STOCK20_H
#define CPP_PRACTICE_STOCK20_H

#include <string>

class Stock {
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() {
        total_val = shares * share_val;
    }

public:
    Stock();
    Stock(const std::string &co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    // core const函数表示不改变调用该函数的对象
    void show() const;
    const Stock & topval(const Stock & s) const;
};

#endif //CPP_PRACTICE_STOCK20_H

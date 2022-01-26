//
// Created by 周天斌 on 2021/12/23.
//

#ifndef CPP_PRACTICE_ACCTABC_H
#define CPP_PRACTICE_ACCTABC_H

#include <iostream>
#include <string>

// Abstract Base Class
class AccABC {
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };

    const std::string &FullName() const { return fullName; }

    long AcctNum() const { return acctNum; }

    Formatting SetFormat() const;

    void Restore(Formatting &f) const;

public:
    AccABC(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);

    void Deposit(double amt);

    double Balance() const { return balance; }

    // core pure virtual function
    virtual void ViewAcct() const = 0;

    // core pure virtual function
    virtual void Withdraw(double amt) = 0;

    virtual ~AccABC() {}
};

// Brass Account Class
class Brass : public AccABC {
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0) : AccABC(s, an, bal) {}

    virtual void Withdraw(double amt);

    virtual void ViewAcct() const;

    virtual ~Brass() {};
};

// Brass Plus Account class
class BrassPlus : public AccABC {
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &s = "Nullbody", long na = -1, double bal = 0.0,
              double ml = 500, double r = 1.0);

    BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);

    virtual void ViewAcct() const;

    virtual void Withdraw(double amt);

    void ResetMax(double m) { maxLoan = m; }

    void ResetRate(double r) { rate = r; }

    void ResetOwes() { owesBank = 0; }
};

#endif //CPP_PRACTICE_ACCTABC_H

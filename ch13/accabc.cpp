//
// Created by 周天斌 on 2021/12/23.
//

#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

// Abstract Base Class
AccABC::AccABC(const std::string &s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AccABC::Deposit(double amt) {
    if (amt < 0) {
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    } else {
        balance += amt;
    }
}

void AccABC::Withdraw(double amt) {
    balance -= amt;
}

// protected methods for formatting
AccABC::Formatting AccABC::SetFormat() const {
// set up ###.## format
    Formatting f;
    f.flag =
            cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AccABC::Restore(Formatting &f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// Brass methods
void Brass::Withdraw(double amt) {
    if (amt < 0) {
        cout << "Withdraw amount must be positive; "
             << "withdrawal canceled.\n";
    } else if (amt <= Balance()) {
        AccABC::Withdraw(amt);
    } else {
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
    }
}

void Brass::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}

// Brass Plus mehtods
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r) : AccABC(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// core use implicit copy constructor
BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AccABC(ba) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const {
    Formatting f = SetFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt) {
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        AccABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AccABC::Withdraw(amt);
    } else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    Restore(f);
}
//
// Created by 周天斌 on 2021/12/7.
//
#include <string>
#ifndef CPP_PRACTICE_NAMESP_H
#define CPP_PRACTICE_NAMESP_H
namespace pers {
    struct Person {
        std::string fname;
        std::string lname;
    };
    void getPerson(Person &);
    void showPerson(const Person &);
}

namespace debts {
    using namespace pers;
    struct Debt {
        Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
}

#endif //CPP_PRACTICE_NAMESP_H

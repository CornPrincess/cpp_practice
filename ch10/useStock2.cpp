//
// Created by 周天斌 on 2021/12/9.
//

#include <iostream>
#include "stock20.h"

const int STKS = 4;

int main() {
    // create an array of initialized objects
    Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
            Stock("Fleep Enterprises", 60, 6.5)
    };

    Stock arr[1] = {
            Stock()
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++) {
        stocks[st].show();
    }
    std::cout << "---------------------------------------------\n";
    for (st = 0; st < STKS; st++) {
        // core 数组越界，不报错
        arr[st].show();
    }
    // set pointer to first element
    const Stock *top = &stocks[0];
    for (st = 1; st < STKS; st++) {
        top = &top->topval(stocks[st]);
    }
    // now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
    for (st = 0; st < STKS; st++) {
        stocks[st].show();
    }
    std::cout << "---------------------------------------------\n";
    top->show();
    std::cout << "---------------------------------------------\n";
    std::cout << "arr address: " << arr << std::endl;
    std::cout << "arr[1] address: " << &arr[1] << std::endl;
    std::cout << "stocks address: " << stocks << std::endl;
    std::cout << "---------------------------------------------\n";
    // core 对于剩余的后3个元素会使用默认构造函数创建
    Stock arr2[7] = {
            Stock(),
            Stock("name2"),
            Stock("name3", 1),
            Stock("name4", 2, 2.2)
    };
    for (st = 0; st < 7; st++) {
        arr2[st].show();
    }
    return 0;
}
//
// Created by 周天斌 on 2021/12/21.
//

#include "tabtenn0.h"
#include <iostream>

// core 直接使用 string 的复制构造函数将 fristname 初始化为fn
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) {

}

// core 为 firstname 调用默认构造函数，在调用string 的赋值运算符奖firstname设置为fn
//TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) {
//    firstname = fn;
//    lastname = ln;
//    hasTable = ht;
//}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}
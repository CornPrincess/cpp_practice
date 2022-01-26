//
// Created by 周天斌 on 2021/12/22.
//

#include "tabtenn1.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : firstname(fn), lastname(ln),
                                                                                    hasTable(ht) {

}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}


void TableTennisPlayer::Show() const {
    std::cout << "TableTennisPlayer: ";
    Name();
    std::cout << std::endl;
}

// RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht) {
    rating = r;
}

// core 如果没有在成员初始化列表调用基类构造函数，那么将调用默认的基类构造函数，与如下的代码等效
//RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) {
//    rating = r;
//}

//RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennisPlayer(){
//    rating = r;
//}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp), rating(r) {

}

void RatedPlayer::Show() const {
    std::cout << "RatedPlayer: ";
    Name();
    std::cout << std::endl;
}
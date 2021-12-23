//
// Created by 周天斌 on 2021/12/22.
//

#include "tabtenn1.h"
#include <iostream>
void showr(TableTennisPlayer &);
void showp(TableTennisPlayer *);
void showv(TableTennisPlayer);

int main() {
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();
    if (rplayer1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;
    // initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    TableTennisPlayer * t = &player1;
    RatedPlayer * r = &rplayer1;

    cout << "================================" << endl;
    showr(player1);
    showr(rplayer1);
    showp(t);
    showp(r);
    // core 按值传值只会传送rplayer1中 player1的部分，没有多态的特性
    showv(player1);
    showv(rplayer1);
}

void showr(TableTennisPlayer & t) {
    t.Show();
}

void showp(TableTennisPlayer * p) {
    p->Show();
}

void showv(TableTennisPlayer v) {
    v.Show();
}
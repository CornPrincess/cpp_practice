//
// Created by 周天斌 on 2021/12/21.
//

#include <iostream>
#include "tabtenn0.h"

int main() {
    using std::cout;
    TableTennisPlayer player1("Chunk", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player2.Name();
    if (player2.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";

    return 0;
}
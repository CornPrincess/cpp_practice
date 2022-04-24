//
// Created by 周天斌 on 2021/12/21.
//

#ifndef CPP_PRACTICE_TABTENN0_H
#define CPP_PRACTICE_TABTENN0_H

#include <string>

using std::string;

// simple base class
class TableTennisPlayer {
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none",
                      const string & ln = "none",
                      bool ht = false);
    void Name() const;
    bool HasTable() const {
        return hasTable;
    }
    void RestTable(bool v) {
        hasTable = v;
    }
};

#endif //CPP_PRACTICE_TABTENN0_H

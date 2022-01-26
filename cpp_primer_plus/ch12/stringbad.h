//
// Created by 周天斌 on 2021/12/12.
//
#include <iostream>

#ifndef CPP_PRACTICE_STRINGBAD_H
#define CPP_PRACTICE_STRINGBAD_H

class StringBad {
private:
    // pointer to the string
    char *str;
    // length of string
    int len;
    // number of objects
    static int num_strings;
public:
    // default constructor
    StringBad();

    // constructor
    StringBad(const char *s);

    // destructor
    ~StringBad();

    char *getStr() {
        return str;
    }

    // friend function
    friend std::ostream &operator<<(std::ostream &os, const StringBad &st);

    // operate= method
    StringBad &operator=(const StringBad &st);

    // copy constructor
    StringBad(const StringBad &st);
};

#endif //CPP_PRACTICE_STRINGBAD_H

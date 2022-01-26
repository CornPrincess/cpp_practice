//
// Created by 周天斌 on 2021/12/13.
//
#include <iostream>

#ifndef CPP_PRACTICE_STRING1_H
#define CPP_PRACTICE_STRING1_H
using std::ostream;
using std::istream;

class String {
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    // constructors and other mnethods
    // default constructors
    String();

    // constructor
    String(const char *s);

    // copy constructor
    String(const String &);

    // destructor
    ~String();

    int length() const {
        return len;
    }

    // overload operator methods
    String &operator=(const char *);

    String &operator=(const String &);

    char &operator[](int i);

    const char &operator[](int i) const;

    // overload operator friend methods
    friend bool operator<(const String &st, const String &st2);

    friend bool operator>(const String &st, const String &st2);

    friend bool operator==(const String &st, const String &st2);

    friend ostream &operator<<(ostream &os, const String &st);

    friend istream &operator>>(istream &os, String &st);

    // static function
    static int HowMany();
};

#endif //CPP_PRACTICE_STRING1_H

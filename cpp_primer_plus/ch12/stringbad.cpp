//
// Created by 周天斌 on 2021/12/12.
//

#include "stringbad.h"
#include <cstring>

using std::cout;

// initializing static class member
int StringBad::num_strings = 0;

// class methods
// construct StringBad from C string
StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created.\n";
}

StringBad::StringBad(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created.\n";
}

StringBad::~StringBad() {
    --num_strings;                      // required
    delete[] str;
    cout << "\"" << str << "\" object " << "(str address=" << (int *) str << ")" << "deleted, ";   // FYI
    cout << num_strings << " left\n";   // FYI
}

std::ostream &operator<<(std::ostream &os, const StringBad &st) {
    os << st.str;
    return os;
}

StringBad &StringBad::operator=(const StringBad &st) {
    // core  与自己比较
    if (this == &st) {
        return *this;
    }
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << "operator = called.\n";
    return *this;
}

StringBad::StringBad(const StringBad &st) {
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_strings << ": \"" << str << "\" (copy constructor) object created.\n";
}
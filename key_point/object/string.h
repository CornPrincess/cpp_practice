//
// Created by 周天斌 on 2022/4/7.
//

#ifndef CPP_PRACTICE_STRING_H
#define CPP_PRACTICE_STRING_H

#include <cstring>
#include <iostream>
class String {
private:
    char* m_data;
public:
    String(const char* cstr = 0);
    String(const String& str);
    ~String();
    String& operator= (const String& str);
    char* get_c_str() const {return m_data;}

    friend std::ostream& operator<< (std::ostream &, const String & str);
};

String::String(const char *cstr) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::String(const String &str) {
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

String &String::operator=(const String &str) {
    if (&str == this) {
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

String::~String() {
    delete[] m_data;
}

std::ostream& operator<< (std::ostream & os, const String & str) {
    os << str.get_c_str() << std::endl;
    return os;
}
#endif //CPP_PRACTICE_STRING_H

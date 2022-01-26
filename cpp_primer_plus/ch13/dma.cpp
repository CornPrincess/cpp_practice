//
// Created by 周天斌 on 2021/12/23.
//

#include <iostream>
#include "dma.h"

using std::cout;
using std::endl;

// baseDMA methods
baseDMA::baseDMA(const char *l, int r) {
    cout << "********baseDMA base constructor ********" << endl;
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) {
    cout << "******** baseDMA copy constructor********" << endl;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA() {
    cout << "******** baseDMA destructor********" << endl;
    delete[] label;
}

baseDMA &baseDMA::operator=(const baseDMA &rs) {
    cout << "******** baseDMA assignment method********" << endl;
    if (this == &rs) {
        return *this;
    }
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs) {
    os << "baseDMA <<" << std::endl;
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &ls) {
    os << "lacksDMA <<" << std::endl;
    os << (const baseDMA &) ls;
    os << "color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l, r) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs) {
    cout << "******** hasDMA copy constructor********" << endl;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
    cout << "******** hasDMA destructor********" << endl;
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs) {
    cout << "******** hasDMA assignment method ********" << endl;
    if (this == &hs) {
        return *this;
    }
    baseDMA::operator=(hs);
    delete[] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &hs) {
    os << "hasDMA <<" << std::endl;
    // core type cast 调用基类的友元
    os << (const baseDMA &) hs;
    os << "style: " << hs.style << std::endl;
    return os;
}

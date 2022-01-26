//
// Created by 周天斌 on 2021/12/23.
//

#ifndef CPP_PRACTICE_DMA_H
#define CPP_PRACTICE_DMA_H
#include <iostream>

// Base Class Using DMA
class baseDMA {
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream  & operator<<(std::ostream & os, const baseDMA & rs);
};

// derived class without DMA
// no destructor
// use implicit copy constructor
// use implicit assignment operator
class lacksDMA: public baseDMA {
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};

// derived class with DMA
class hasDMA : public baseDMA{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    friend std::ostream  & operator<<(std::ostream & os, const hasDMA & hs);
};
#endif //CPP_PRACTICE_DMA_H

//
// Created by 周天斌 on 2021/12/14.
//

#include "string1.h"
#include <iostream>

int main() {
    {
        String * string = new String("test");
        std::cout << "string *: " << string << std::endl;
        std::cout << "(*string): " << *string << std::endl;
        std::cout <<  (string->HowMany()) << std::endl;
        // 一定要显示使用 delete， 才会调用析构函数
        delete string;
    }
    return 0;
}
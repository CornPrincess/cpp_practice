//
// Created by 周天斌 on 11/13/21.
//

#include <iostream>
int main() {
    int  carrots;
    std::cout << "How many carrots do you have?" << std::endl;
    std::cin >> carrots;
    std::cout << "Here are tow more. " << std::endl;
    carrots += 2;
    std::cout << "Now you have " << carrots << " carrots." << std::endl;
    return 0;
}
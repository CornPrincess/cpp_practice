//
// Created by 周天斌 on 2022/2/9.
//

#include <iostream>

double func1(int);
double func2(int);

// the second argument is pointer to a type double function that takes a type int argument.
void estimate(int lines, double (*pf)(int));

int main() {
    int code = 5;
    std::cout << "Here's func1's estimate:\n";
    estimate(code, func1);
    std::cout << "Here's func2's estimate:\n";
    estimate(code, func2);
    return 0;
}

double func1(int lns) {
    return 0.05 * lns;
}

double func2(int lns) {
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int)) {
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hour(s)\n";
}
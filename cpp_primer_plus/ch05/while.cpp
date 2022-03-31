//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
int main() {
    using std::cout;
    using std::endl;
    int count = 1;
    //  比较时先用原来的值进行比较，然后+1
    // count++ < 5 是一个顺序点，确保对count的改动生效之后才会进行下一条语句0
    while (count++ < 5) {
        // 这里打印的是++之后的值
        cout << count << endl;
    }
}
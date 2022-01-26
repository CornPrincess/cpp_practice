//
// Created by 周天斌 on 2021/12/1.
//

#include <iostream>
const int ArSize = 80;

char * left(const char * str, int n = 1);

int main() {
    using namespace std;
    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);
    char *ps = left(sample, 4);
    cout << ps << endl;
    delete [] ps;       // core free old string
    ps = left(sample);
    cout << ps << endl;
    delete [] ps;       // core free new string
    return 0;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string
char * left(const char * str, int n) {
    // 如惨校验
    if (n < 0) {
        n = 0;
    }
    // 指针形式的数组
    char *p = new char[n+1];
    int i;
    // core 判断条件需要加上字符串的长度
    for (i = 0; i < n && str[i]; i++) {
        // core 指针也能用数组格式
        p[i] = str[i];
    }
    // 后续空格
    while (i <= n) {
        p[i++] = '\0';
    }
    return p;
}
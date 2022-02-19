#include <stdio.h>
#include "head.h"
/* 1. gcc -c add.c sub.c mult.c div.c -I ../include/
 * 2. gcc -shared add.o sub.o div.o mult.o -o libcalc.so
 * 3. mv libcalc.so ../lib
 * 4. gcc main.c  -o app -I ./include/ -l calc -L ./lib/
 * 这里要注意库的名字是 calc， 静态库文件名为 libcalc.so
 * 5. ./app 这里运行是报错了 ./app: error while loading shared libraries: libcalc.so: cannot open shared object file: No such file or directory
 */
int main()
{
    int a = 20;
    int b = 12;
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", subtract(a, b));
    printf("a * b = %d\n", multiply(a, b));
    printf("a / b = %f\n", divide(a, b));
    return 0;
}

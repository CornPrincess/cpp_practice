#include <stdio.h>
#include "head.h"
/* 1. gcc -c add.c sub.c mult.c div.c -I ../include/
 * 2. ar rcs libcalc.a add.o sub.o div.o mult.o
 * 3. mv libcalc.a ../lib
 * 4. gcc main.c  -o app -I ./include/ -l calc -L ./lib/
 * 这里要注意库的名字是 calc， 静态库文件名为 libcalc.a
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

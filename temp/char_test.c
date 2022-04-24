//
// Created by qwskyz on 22-4-23.
//
#include <stdio.h>

int main(void)
{
    char a[11];
    a[0] = 'i'; a[1] = ' '; a[2] = 'l'; a[3] = 'o'; a[4] = 'v';
    //空格字符的单引号内一定要敲空格
    a[5] = 'e'; a[6] = ' '; a[7] = 'y'; a[8] = 'o'; a[9] = 'u';
    //空格字符的单引号内一定要敲空格
    a[10] = '\0';
    char b[11];
    b[0] = 'i'; b[1] = ' '; b[2] = 'm'; b[3] = 'i'; b[4] = 's';
    //空格字符的单引号内一定要敲空格
    b[5] = 's'; b[6] = ' '; b[7] = 'y'; b[8] = 'o'; b[9] = 'u';
    b[10] = '\0';
    //空格字符的单引号内一定要敲空格
    char c[] = "i believe you";
    char d[] = {'i', ' ', 'l', 'i', 'k', 'e', ' ', 'y', 'o', 'u','\0'};
    //空格字符的单引号内一定要敲空格
    char e[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    //空格字符的单引号内一定要敲空格
    char f[] = "上课睡觉觉, 下课打闹闹, 考试死翘翘";
    char g[10] = "";
    char h[10];
    printf("a = %s\n", a);  //输出字符串用%s, 输出参数必须写数组名
    printf("b = %s\n", b);
    printf("c = %s\n", c);
    printf("d = %s\n", d);
    printf("e = %s\n", e);
    printf("f = %s\n", f);
    printf("g = %s\n", g);
    printf("h = %s\n", h);
    int i;
    for (i = 0; i < 10; i++) {
        int cc = h[i];
        printf("char: %c, int: %d\n", h[i], cc);
    }
    return 0;
}
//
// Created by qwskyz on 2022/2/16.
//

#include <stdio.h>

int main() {
    int a = 10;
#ifdef DEBUG
    printf("the content inside ifdef\n");
#endif
    for (int i = 0; i < 3; i++) {
        printf("hello GCC!\n");
    }
    return 0;
}
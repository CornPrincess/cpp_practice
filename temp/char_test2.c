//
// Created by qwskyz on 22-4-23.
//

#include <stdio.h>
#include <error.h>

#define SIZE 23

char name[SIZE + 1];

int main(void) {
    printf("hello whiami");
    int res;
    //res = whoami(name, SIZE + 1);
    if (res == -1) {
        //errno = EINVAL;
    } else {
        printf("name: %s, res: %d\n", name, res);
    }
    return res;
}

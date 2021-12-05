#include <stdio.h>

int main(){
    int x = 10;
    int *ptr = &x;
    int *pri = ptr;
    printf("%x %x %x\n",*ptr, *pri, x);
    return 0;
}


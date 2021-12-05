#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void ht_timing(void (*f)(void))
{
    clock_t t = clock();
    (*f)();
    printf("[ht_timing] %.3lf sec\n", (double)(clock() - t) / CLOCKS_PER_SEC);
}

void func(){
    sleep(1);
}

int main(){
    ht_timing(func);
    ht_timing(func);
    ht_timing(func);
    return 0;
}

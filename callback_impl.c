/*
 * To Implement the callback functionality in C
 * using function pointers.
 * -Aditya Sharma
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int seconds = 0;

void timer_callback(int val){
    printf("Well the timeout occurred with val: %d\n", val);
}

void start_timer(void (*callback(int))){
    int i = 0;
    //just wait for three seconds and then callback
    while(i<3){
        sleep(1);
        seconds++;
        i++;
    }
    //call to call_back function
    callback(seconds);
}

int main()
{
    void *ptr = &timer_callback;
    start_timer(ptr);
    start_timer(ptr);
    return 0;
}

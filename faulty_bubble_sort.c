#include <stdio.h>
#include <math.h>

void useless_function(long *arr, int size){
    printf("Bubble Sort :\n");
    for(int i = 0; i < size; i++){
        printf("Bubble Sort :\n%ld  ",arr[i]);
    }
    return;
}

int main(){
    long elements[32];
    //srand(time(NULL));
    printf("rand == %d\n\n", rand());
    for (int i =0; i < rand() % sizeof(elements); i++){
        printf("i = %d\n",rand());
        elements[i] = rand();
    }

    for(int i = 0; i < 32; i++){
        printf("%ld  ",elements[i]);
    }

    useless_function(elements, 32);
    return 0;
}

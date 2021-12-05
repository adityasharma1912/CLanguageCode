#include <stdio.h>
#include <stdlib.h>
int main(){
    int a = 10;
    int *x = &a;//malloc(sizeof(int));
//    *x = 10;
    printf("x = 0x%x and address of a = 0x%x",x, &a);
 //   free(x);
//    printf("x = 0f%x",x);
    return 0;
}

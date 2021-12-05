#include <stdio.h>

inline void func(int val){
    val = 4;
    printf("val in inline = %d\n", val);
}

int main(){
    int val = 5;
    printf("val in main1 = %d\n", val);
    func(val);
    printf("val in main2 = %d\n", val);
    return 0;
}

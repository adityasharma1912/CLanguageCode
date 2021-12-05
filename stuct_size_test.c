#include <stdio.h>

struct something{
    int var1;
    char var2;
}__attribute__((packed));

struct parent{
    struct something one;
    void *ptr;
    //char name;
}__attribute__((packed));

int main(){
    struct parent object;
    printf("size of(structure parent) = %d\n",sizeof(struct parent));
    printf("&of parent object = %x\n",&object);
    printf("&of parent object pointer = %x\n",&object.ptr);
    return 0;
}

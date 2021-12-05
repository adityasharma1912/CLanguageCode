#include <stdio.h>
#include <stdlib.h>

struct s_tag
{
        int a;
        int *ptr;
};

void FunctionCall(void* tag);
int main()
{
struct s_tag *tag;

        tag = malloc(sizeof(struct s_tag));

        tag->a= 1;
        int b = 2;
        tag->ptr = &b;

        FunctionCall((void*)&tag);

        return 0;
}

void FunctionCall(void* tag)
{
        struct s_tag *my_tag =  (struct s_tag*)tag;
        printf("tag->a = %d\ttag->ptr = %d\n", my_tag->a, my_tag->ptr);
        printf("value = %d", ntohs(5));
}

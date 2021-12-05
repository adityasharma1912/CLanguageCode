#include <stdio.h>

typedef struct abc{
    int value;
    struct abc *left;
    struct abc *right;
}node;

int main(){
    node *head = (node *)malloc(sizeof(node));
    printf("value = %d head->left = 0x%x head->right = 0x%x\n",head->value,
           head->left, head->right);
    return 0;
}

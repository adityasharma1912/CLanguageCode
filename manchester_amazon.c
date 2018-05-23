#include<stdio.h>
#include<stdlib.h>

int* manchester(int* arr,int len){
    int *res = (int *)malloc(sizeof(int)*len);
    res[0] = arr[0];
    for(int i = 0;i<len-1; i++){
        res[i+1] = (arr[i]!=arr[i+1]); // change equality to not equal to
    }
    return res;
}

int main(){
    int arr[] = {0,1,0,0,1,1,1,0,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int *pqr = manchester(arr,len);
    int len2 = sizeof(pqr)/sizeof(pqr[0]);
    for(int i = 0;i<len;i++){
        printf("%d ",pqr[i]);
    }
}

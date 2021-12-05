#include <stdio.h>
#include<string.h>
#define DDET_ENTRY_TSP_BITS 8
#define DDET_ENTRY_TSP_MASK ((1<<DDET_ENTRY_TSP_BITS)-1)

void replacechar(char* str, char find, char replace){
    for (char* p = str; p = strchr(p, '.'); ++p) {
        *p = '_';
    }
}

int main(){
    printf("0x%x\n",DDET_ENTRY_TSP_MASK);
    unsigned long long x = 11533444200563702;
    float power = log(x)/log(2);
    unsigned long long value = pow(2,63);

    printf("power is  = %f\n",power);
    if(value > x){
        printf("value is  = %llu\n",value);
    }

    printf("-----------new----------------\n");
    char *lineage = "cmroot.slb.server.s1";
    char from = '.';
    char to = '_';

    replacechar(lineage,from,to);
    printf("updated String: %s   %s\n",lineage);
    return 0;
}

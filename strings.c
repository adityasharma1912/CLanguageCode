#include <stdio.h>
#include <string.h>
int abc;

void func(){
    int abc = 11;
    printf("\n\nabc : %d\n",abc);
}

int main()
{
   char* haystack = "exec/ls -la | grep pws sdfsdf";
   char* needle = "/";
   char *ret;

   ret = strstr(haystack, needle);
   ret++;
   static int abc = 10;
   func();

   //printf("The new substring is: %s\n", ret);
   return(0);
}



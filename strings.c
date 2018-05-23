#include <stdio.h>
#include <string.h>


int main()
{
   char* haystack = "exec/ls -la | grep pws sdfsdf";
   char* needle = "/";
   char *ret;

   ret = strstr(haystack, needle);
   ret++;

   printf("The new substring is: %s\n", ret);
   return(0);
}

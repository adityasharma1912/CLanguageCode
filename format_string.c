#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char **argv){
	char *FLG = "FLG772882741";
	char *ptr;
	char input[100];
	memset(&input,0,sizeof(char)*100);
	ptr = getenv(argv[1]);
	printf("%p\n",ptr);
	scanf("%s",input);
	printf(input);
	return 0;
}

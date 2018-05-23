#include <stdio.h>
#include <time.h>
int main(){
	unsigned int i = 0;
	clock_t begin = clock();
	for(i;i<4294967295;i++);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Processing completed in %f seconds with i = %ud\n",time_spent,i);
	return 0;
}
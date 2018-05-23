#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int g = 0;
//normal function to execute as a thread
void *threadFunction(void *argv){
	int threadNo = (int *)argv;
	static int s = 0;
	// pthread_mutex_lock(&mutex1);
	for (int i = 0; i < 10; ++i)
	{
		sleep(1);
		printf("Thread Number : %d Vlaue of g = %d and Value of s = %d\n",threadNo,++g,++s);
	}
	// pthread_mutex_unlock(&mutex1);
	// printf("Thread Number : %d Vlaue of g = %d and Value of s = %d\n",threadNo,g,++s);
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t thread_id[30];
        printf("Number of arguments = %d and Argument at index 1 is = %d\n",argc,atoi(argv[1]));
	printf("%s\n", "Creating multiple threads");
	for (int i = 1; i <= 2; ++i)
	{
		pthread_create(&thread_id[i],NULL,threadFunction,i);
	//        pthread_join(thread_id[i],NULL);
	}
	printf("%s%d\n", "Ultimate Value of Global Counter is:",g);
	pthread_exit(NULL);
	return 0;
}

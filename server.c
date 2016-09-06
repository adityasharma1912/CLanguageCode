/*
 * A simple program to show multi-threading in C
 * using POSIX thread with slight introduction of
 * mutual exclusion
 *
 * Created By : Aditya Sharma
 */

#include<stdio.h>
#include<pthread.h>

#define TOTAL_FEASIBLE_CLIENTS 4
int globalVariable;

pthread_mutex_t thread_lock;

int *funcRoutine(void *argv) {
	pthread_mutex_lock(&thread_lock);
	int value_in_thread = (int *) argv;
	for (int i = 1; i < 6; i++) {
		printf("Thread id : %d and Value Passed : %d\n", value_in_thread,
				value_in_thread + i);
		sleep(1);
	}
	pthread_mutex_unlock(&thread_lock);
	//	pthread_exit(0);
	return 0;
}

//this routine must execute first hence I am using mutex here...
int *threadZeroRoutine(void *argv) {
	//	pthread_mutex_lock(&thread_lock);
	int value_in_thread = (int *) argv;
	//set global variable to some value first... here incrementing by 15
	for (int i = 1; i < 6; i++) {
		globalVariable += i;
		printf("Thread id : %d and Global Variable : %d\n", value_in_thread,
				globalVariable);
		sleep(1);
	}
	pthread_mutex_unlock(&thread_lock);
}

int main() {
	pthread_t threadid[TOTAL_FEASIBLE_CLIENTS];
	pthread_mutex_init(&thread_lock, NULL);
	pthread_mutex_lock(&thread_lock); //pthread must attain the lock first so that my 1,2,3 thread will wait for that lock and thread 0 of mine will execute first and unlock the same...
	printf("\nMain thread locked :P\n");
	int value_to_thread = 10;
	for (int i = 0; i < TOTAL_FEASIBLE_CLIENTS; i++) {
		if (i == 0)
			pthread_create(&threadid[i], NULL, threadZeroRoutine,
					((void *) (i)));
		else
			pthread_create(&threadid[i], NULL, funcRoutine, ((void *) (i)));
		//		pthread_join(threadid[i], NULL);
	}
	pthread_mutex_destroy(&thread_lock);
	pthread_exit(NULL);
	printf("END OF MAIN"); //no point of this statement as main thread already exits prior to it
	return 0;
}

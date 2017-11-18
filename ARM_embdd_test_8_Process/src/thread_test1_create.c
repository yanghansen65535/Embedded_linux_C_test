#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void * thread_func(void* arg){
	int *val=arg;
	printf("this is a thread.");
	if(arg!=NULL){
		printf("arg:%d\n",*val);
	}
}
int thread_test1_create(){
	pthread_t tid;
	int t_arg=100;
	if(pthread_create(&tid,NULL,thread_func,&t_arg))
		perror("fail to create thread.");
	sleep(1);
	printf("main thread.\n");
	return 0;
}

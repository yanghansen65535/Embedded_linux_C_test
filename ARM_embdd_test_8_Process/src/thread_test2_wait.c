#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void * func_wait(void* arg){
	int count=0;
	int *num=arg;
	while(1){
		sleep(1);
		printf("th1->arg:%d,count:%d\n",*num,count);
	}
}
void * func_cancel(void * thid){
	pthread_t *num=thid;
	if(pthread_cancel(*num)!=0){
		printf("th2->fail to cancel\n");
	}else{
		printf("th2->success to cancel");
	}
}
int thread_test2_cancel(void){
	pthread_t thid1,thid2;
	int arg=99;
	if(pthread_create(&thid1,NULL,func_wait,&arg))
		perror("fail to create thread1.");
	sleep(2);
	if(pthread_create(&thid2,NULL,func_cancel,&thid1))
		perror("fail to create thread2.");
	pthread_join(thid1,NULL);
	pthread_join(thid2,NULL);
	return 0;
}


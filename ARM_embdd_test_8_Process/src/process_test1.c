#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int process_test1(void) {
	pid_t pid;
	int i;
	pid=fork();
	i=0;
	if(pid<0){
		printf("fail to create process\n");
		return 0;
	}else if(pid==0){
		i=1;
		printf("im child,i:%d\n",i);
	}else{
		printf("im father.child:%d.i:%d\n",pid,i);
	}
	return 0;
}

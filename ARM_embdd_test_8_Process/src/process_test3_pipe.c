#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int process_test3_pipe(void)
{
	pid_t pid;
	int _pipe[2];
	char text1[64]="hello";
	char text2[64];
	pipe(_pipe);
	pid=fork();
	if(pid<0){
		printf("error\n");
		return 0;
	}else if(pid==0){
		printf("father talk:%s.\n",text1);
		//close(_pipe[0]);
		write(_pipe[1],text1,strlen(text1));
		//read(_pipe[0],text2,64);
		//printf("%s\n",text2);
		//close(_pipe[1]);
	}else{
		printf("child,pid:%d.",pid);
		//close(_pipe[1]);
		read(_pipe[0],text2,64);
		printf("%s\n",text2);
		//close(_pipe[0]);
	}

	return 0;
}

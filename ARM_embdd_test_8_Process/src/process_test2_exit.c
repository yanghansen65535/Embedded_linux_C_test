#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int bye(void)
{
	printf("exit\n");
	return 0;
}

int bye1(void)
{
	printf("call this first\n");
	return 0;
}

int process_test2_exit_main(void)
{
	int i;
	i=atexit(bye);
	if(i!=0){
		fprintf(stderr,"cannot set exit func bye\n");
		return EXIT_FAILURE;
	}
	i=atexit(bye1);
	if(i!=0){
		fprintf(stderr,"cannot set exit func bye1\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

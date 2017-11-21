#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<termios.h>
#include<errno.h>

int SP_open_close(void) {
	int fd;
	fd=open("/dev/ttyS0",O_RDWR);
	if(fd==-1){
		perror("open ttyS0");
		return 0;
	}
	printf("open success\n");
	return 0;
}


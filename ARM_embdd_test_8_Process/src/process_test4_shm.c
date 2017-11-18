#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int process_test4_shm(void){
	pid_t pid,pid_wait;
	int status;
	pid=fork();
	struct shmid_ds buf;
	if(pid<0){
		printf("error\n");
		return 0;
	}else if(pid>0){
		printf("father:");
		int shmid;
		char *ptr;
		char *shm_str="string in a share mem\n";
		shmid=shmget(0x90,1024,SHM_W|SHM_R|IPC_CREAT|IPC_EXCL);
		if(shmid==-1){
			perror("create share mem");
		}
		ptr=(char*)shmat(shmid,0,0);
		if(ptr==(void*)-1){
			perror("get share mem");
		}
		strcpy(ptr,shm_str);
		shmdt(ptr);
		pid_wait=waitpid(pid,&status,0);
		if(shmctl(shmid,IPC_RMID,&buf)!=0){
			printf("error");
			return 0;
		}
	}else{
		printf("child:");
		int shmid;
		char *ptr;
		shmid=shmget(0x90,1024,SHM_W|SHM_R|IPC_EXCL);
		if(shmid==-1){
			perror("create share mem");
		}
		ptr=(char*)shmat(shmid,0,0);
		if(ptr==(void*)-1){
			perror("get share mem");
		}
		printf("%s",ptr);
		shmdt(ptr);
	}
	return 0;
}

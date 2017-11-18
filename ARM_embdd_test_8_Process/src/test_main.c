/*
 ============================================================================
 Name        : ARM_enbdd_test_8_Process.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

int process_test1();
int process_test2_exit_main(void);
int process_test3_pipe(void);
int process_test4_shm(void);
int thread_test1_create(void);

int main(void) {
	thread_test1_create();
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>

void *func1(){
	for(int i=0;i<5;i++)
                printf("[Thread1] thread-id:%u pid:%d ppid:%d\n",(unsigned int)pthread_self(),getpid(),getppid());
}

void *func2(){
	for(int i=0;i<5;i++)
                printf("[Thread2] thread-id:%u pid:%d ppid:%d\n",(unsigned int)pthread_self(),getpid(),getppid());
}

int main(){
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,func1,NULL);
	pthread_create(&tid2,NULL,func2,NULL);

	for(int i=0;i<5;i++)
		printf("[Main] thread-id:%u pid:%d ppid:%d\n",(unsigned int)pthread_self(),getpid(),getppid());

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}

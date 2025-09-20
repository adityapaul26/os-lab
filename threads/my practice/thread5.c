#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *func(){
	int i,res;
	res= pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
	if(res!=0){
		printf("error");
		exit(EXIT_FAILURE);
	}
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
	printf("The thread is still running");
	for(int i=0;i<10;i++){
		printf("the thread function is running%d\n",i);
	}
	pthread_exit(0);
}

int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,func,NULL);
	printf("thread is beginning cancellation- \n");
	pthread_cancel(tid);
	printf("waiting for the thread & finish-\n");\
	pthread_join(tid,NULL);
	return 0;
}

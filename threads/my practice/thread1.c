#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<string.h>

void *addOne(void *a){
	int val=*(int *)a;
	val= val+1;
	for(int i=0;i<val;i++)
		printf("The loop should run %d times:\n",val);
}

int main(){
	pthread_t tid;
	int n=5;
	pthread_create(&tid, NULL,addOne,&n);
	printf("This is the main thread running:\n");
	pthread_join(tid,NULL);
}

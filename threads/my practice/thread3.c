#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct{
	int num1;
	int num2;
	int result;
}data;

void *func(void *nums){
	data *a= (data *)nums;
	a->result = a->num1 +a->num2;
	printf("The result is:%d",a->result);
}

int main(){
	data num = {10,20,0};
	pthread_t tid;
	pthread_create(&tid,NULL,func,&num);

	printf("[Main] running...");

	pthread_join(tid,NULL);
}

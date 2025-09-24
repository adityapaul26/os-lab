#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *func(void *nums){
	int *arr= (int *)nums;
	int sum=0;
	for(int i=0;i<5;i++) sum= sum+ arr[i]; 
	printf("The sum is:%d",sum);
}

int main(){
	int arr[5] = {1,2,3,4,5};
	pthread_t tid;
	pthread_create(&tid,NULL,func,arr);

	printf("[Main] running...");

	pthread_join(tid,NULL);
}

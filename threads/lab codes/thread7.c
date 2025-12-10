#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *sum(void *args){
    int *arr=(int *)args;
    int *res = malloc(sizeof(int));
    *res=arr[0]+arr[1]; 
    pthread_exit((void*)res);
}

int main(){
    pthread_t tid;
    int arr[]={1,2};
    pthread_create(&tid,NULL,sum,(void*)arr);
    void *result;
    pthread_join(tid,&result);
    printf("the sum is:%d",*(int *)result);
    return 0;
}

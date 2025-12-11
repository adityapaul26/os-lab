#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<semaphore.h>
#include<string.h>

char buffer[100];
sem_t sem;


void* writer(void *arg){ 
    while(true){
        // scanf(" %c",&buffer);
        // printf("Enter: "); avoid prints
        fgets(buffer,sizeof(buffer),stdin);
        sem_post(&sem);
    }
}

void* reader(void *arg){
    while(true){
        sem_wait(&sem);
        printf("reading!-%ld\n",strlen(buffer)-1);
    }
}

int main(){
    pthread_t writer1,reader1;
    sem_init(&sem,0,0);
    pthread_create(&writer1,NULL,writer,NULL);
    pthread_create(&reader1,NULL,reader,NULL);
    pthread_join(writer1,NULL);
    pthread_join(reader1,NULL); 
    sem_destroy(&sem);
    return 0;
}



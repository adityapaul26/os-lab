#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
    
    pid_t pid;

    pid = fork();

    if(pid==0){
        execl("/bin/ls","ls",NULL);
    }else{
        //wait
        sleep(2);
        wait(NULL);
    }
}

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    pid_t pid;

    int pipes[2];

    if(pipe(pipes)==-1){
        perror("pipe fault");
        exit(EXIT_FAILURE);
    }

    //here we convert a array of size 2 to a pipe .. from the 0th index we take the output and in 1th index we put the input.

    // 0th index => output
    // 1th index => input

    pid = fork();

    if(pid > 0){
        //parent process
        close(pipes[0]);
        char msg[] = "[PARENT]hello form lightangel26!\n";
        printf("[PARENT] im writing now ...\n");
        write(pipes[1],msg,strlen(msg)+1);
        printf("[PARENT] writing done!\n");
        close(pipes[1]);
    }else{
        //child process
        close(pipes[1]);
        char buffer[100];
        printf("[CHILD] im printing data now!\n");
        read(pipes[0],buffer,sizeof(buffer));
        printf("[CHILD]parent says...\n");
        printf("%s",buffer);
        close(pipes[0]);
        wait(NULL);
        sleep(3);
    }

    return 0;
}

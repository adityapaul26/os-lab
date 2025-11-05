
//file2.c

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    char buffer1[100];
    int index;
    char newBuffer[100];
    int fd1 ,fd2, fd3;

    fd1= open("pipe1",O_RDONLY);
    read(fd1,buffer1,sizeof(buffer1));
    printf("%s",buffer1);
    close(fd1);
    
    fd2= open("pipe2",O_RDONLY);
    read(fd2,&index,sizeof(index));
    printf("%d",index);
    close(fd2);
    
    strncpy(newBuffer, buffer1, index);

    fd3= open("pipe1",O_WRONLY);
    write(fd3,newBuffer,sizeof(newBuffer));
    close(fd3);
    
    return 0;
}
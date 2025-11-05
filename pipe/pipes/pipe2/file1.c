// in this code we need to create 2 files that are supposed to communicate among eachother ... 
// from file1.c send a word and an index to file2 .. in file2 splice the string till that index .. for example -- file1 sends 'lightangel' and '5' then it must send 'light' back to file1 and then file1 displays that.

//file1.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    char message[100];
    int index;
    char finalMessage[100];

    printf("Enter a word:");
    scanf("%s",message);
    printf("Enter how much to splice:");
    scanf("%d", &index);

    int fd1 ,fd2, fd3;

    unlink("pipe1");
    unlink("pipe2");
    
    mkfifo("pipe1",0666);
    mkfifo("pipe2",0666);

    fd1 = open("pipe1", O_WRONLY);
    write(fd1, message, strlen(message) + 1);
    close(fd1);

    fd2 = open("pipe2", O_WRONLY);
    write(fd2, &index, sizeof(index));
    close(fd2);

    fd3 = open("pipe1",O_RDONLY);
    read(fd3,finalMessage,sizeof(finalMessage));
    close(fd3);

    finalMessage[index] = '\0';
    
    printf("The spliced string is: %s",finalMessage);

    return 0;
}
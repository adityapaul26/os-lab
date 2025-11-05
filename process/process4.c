// write a program that creates 3 child processes, where the first one prints
// 'Hi!', 2nd one prints 'Hello!' and the 3rd one prints 'Hello world!'

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  pid_t pid;

  // fork();
  // fork();
  // fork(); // this wont work as this actually creates more than 3 child
  // processes

  pid = fork();
  // for this case we ignore the case of pid == -1 (fork failed)
  if (pid == 0) {
    // child process
    printf("Hi!\n");
    sleep(3);
  } else {
    // parent process
    wait(NULL);
    pid = fork();
    if (pid == 0) {
      // child process
      printf("Hello!\n");
      sleep(3);
    } else {
      // parent process
      wait(NULL);
      pid = fork();
      if (pid == 0) {
        // child process
        printf("Hello world!\n");
        sleep(3);
      } else {
        // parent process
        wait(NULL);
      }
    }
  }

  return 0;
}

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd;
  char msg[] = "hello from the writer-lightangel26...";
  unlink("the-pipe");
  mkfifo("the-pipe", 0666);

  if (mkfifo("the-pipe", 0666) == -1) {
    perror("mkfifo failed");
    exit(EXIT_FAILURE);
  }

  fd = open("the-pipe", O_WRONLY);

  if (fd == -1) {
    perror("pipe fault!");
    exit(EXIT_FAILURE);
  }

  printf("[WRITER] Im writing now\n");

  if (write(fd, msg, sizeof(msg)) == -1) {
    perror("write failed");
    close(fd);
    exit(EXIT_FAILURE);
  }

  close(fd);
  printf("[WRITER] My writing is complete now!\n");
  return 0;
}
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

  if (fd == -1) {
    perror("pipe fault!");
    exit(EXIT_FAILURE);
  }

  printf("[WRITER] Im writing now\n");
  fd = open("the-pipe", O_WRONLY);
  write(fd, msg, sizeof(msg));
  close(fd);
  printf("[WRITER] My writing is complete now!\n");
  return 0;
}
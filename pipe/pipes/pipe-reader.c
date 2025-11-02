#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd;
  char buffer[100];
  fd = open("the-pipe", O_RDONLY);
  read(fd, buffer, sizeof(buffer));
  printf("[READER] Im reading now!\n The text is :%s", buffer);
  close(fd);
  printf("[READER] My reading is complete now!\n");
  return 0;
}
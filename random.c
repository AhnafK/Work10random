#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int randomG(){
  int fd = open("/dev/random", O_RDONLY);
  int * randish;
  read(fd, randish, sizeof(int));
  close(fd);
  return *randish;
}

int main(){
  printf("Generating random numbers:\n");
  int randnums[10];
  int rerandnums[10];
  for(int x = 0; x < 10; x++){
    int f = randomG();
    randnums[x] = f;
    printf("\t random %d: %d\n", x, f);
  }
  printf("Writing nums to file txt.txt\n");
  int fd = open("txt.txt", O_CREAT|O_RDWR, 0777);
  write(fd, randnums, 40);
  read(fd, rerandnums,40);
  printf("Reading from file:\n");
  for(int x = 0; x < 10; x++){
    printf("\t random %d: %d\n", x, rerandnums[x]);
  }
  close(fd);
}

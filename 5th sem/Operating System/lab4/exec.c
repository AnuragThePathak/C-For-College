#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  int i;
  if (argc != 3) {
    printf("\nInsufficient arguments to load program");
    printf("\nUsage: ./a.out <path> <cmd>\n");
    exit(-1);
  }
  pid = fork();
  if (pid < 0) {
    printf("Fork failed");
    exit(-1);
  } else if (pid == 0) {
    printf("Child process\n");
    i = execl(argv[1], argv[2], 0);
    if (i < 0) {
      printf("%s program not loaded using exec system call\n", argv[2]);
      exit(-1);
    } else {
      wait(NULL);
      printf("Child Terminated\n");
    }
  }
  return 0;
}
#include <stdbool.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

bool isPrime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0)
      return false;
  return true;
};

int main() {
  int pfd[2];
  int returnstatus;
  int pid;
  returnstatus = pipe(pfd);
  if (returnstatus == -1) {
    printf("Unable to create pipe\n");
    return 1;
  }
  pid = fork();
  if (pid == 0) {

    int fib[25];
    for (int i = 0; i < 25; i++) {
      if (i <= 1)
        fib[i] = i;
      else
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    write(pfd[1], fib, sizeof(fib));
  } else if (pid > 0) {
    wait(NULL);
    int fib2[25];
    read(pfd[0], fib2, sizeof(fib2));
    for (int i = 0; i < 25; i++) {
      if (isPrime(fib2[i]))
        printf("%d ", fib2[i]);
    }
    printf("\n");
  } else {
    return (1);
  }
}
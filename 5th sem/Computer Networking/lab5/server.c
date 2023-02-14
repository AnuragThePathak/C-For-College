#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080

unsigned long long int factorial(unsigned long long int n) {
  if (n == 0)
    return 1;
  unsigned long long int i = n, fact = 1;
  while (n / i != n) {
    fact = fact * i;
    i--;
  }
  return fact;
}

int main() {
  int sockfd;
  unsigned long long int num, n, fact;
  struct sockaddr_in servaddr, cliaddr;

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }
  memset(&servaddr, 0, sizeof(servaddr));
  memset(&cliaddr, 0, sizeof(cliaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  int len;

  len = sizeof(cliaddr);
  while (1) {
    n = recvfrom(sockfd, &num, sizeof(num), MSG_WAITALL,
                 (struct sockaddr *)&cliaddr, &len);
    fact = factorial(num);
    sendto(sockfd, &fact, sizeof(fact), MSG_CONFIRM,
           (const struct sockaddr *)&cliaddr, len);
    printf("%llu sent\n", fact);
  }

  return 0;
}
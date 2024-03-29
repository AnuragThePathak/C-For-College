#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define W 5
#define P1 50
#define P2 10

char a[10];
char b[10];
void alpha9(int);

int main() {
  struct sockaddr_in address, client;
  int server_fd, addr_len, new_socket, i, j, c = 1, f;
  unsigned int s1;
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  address.sin_family = AF_INET;
  address.sin_port = 6500;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  listen(server_fd, 1);
  addr_len = sizeof(client);
  new_socket = accept(server_fd, (struct sockaddr *)&client, (socklen_t *)&addr_len);
  printf("\nTCP Connection Established.\n");
  s1 = (unsigned int)time(NULL);
  srand(s1);
  strcpy(b, "Time Out ");
  recv(new_socket, a, sizeof(a), 0);
  f = atoi(a);
  while (1) {
    for (i = 0; i < W; i++) {
      recv(new_socket, a, sizeof(a), 0);
      if (strcmp(a, b) == 0) {
        break;
      }
    }
    i = 0;
    while (i < W) {
      j = rand() % P1;
      if (j < P2) {
        send(new_socket, b, sizeof(b), 0);
        break;
      } else {
        alpha9(c);
        if (c <= f) {
          printf("\nFrame %s Received ", a);
          send(new_socket, a, sizeof(a), 0);
        } else {
          break;
        }
        c++;
      }
      if (c > f) {
        break;
      }
      i++;
    }
  }
  close(new_socket);
  close(server_fd);
  return 0;
}

void alpha9(int z) {
  int k, i = 0, j, g;
  k = z;
  while (k > 0) {
    i++;
    k = k / 10;
  }
  g = i;
  i--;
  while (z > 0) {
    k = z % 10;
    a[i] = k + 48;
    i--;
    z = z / 10;
  }
  a[g] = '\0';
}
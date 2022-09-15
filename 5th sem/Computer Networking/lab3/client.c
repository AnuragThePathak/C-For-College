#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>

#define W 5
#define P1 50
#define P2 10

char a[10];
char b[10];
void alpha9(int);

int main() {
  struct sockaddr_in srv, client;
  int s, n, sock, i, j, c = 1, f;
  unsigned int s1;
  s = socket(AF_INET, SOCK_STREAM, 0);
  srv.sin_family = AF_INET;
  srv.sin_port = 6500;
  srv.sin_addr.s_addr = inet_addr("127.0.0.1");
  bind(s, (struct sockaddr *)&srv, sizeof(srv));
  listen(s, 1);
  n = sizeof(client);
  sock = accept(s, (struct sockaddr *)&client, &n);
  printf("\nTCP Connection Established.\n");
  s1 = (unsigned int)time(NULL);
  srand(s1);
  strcpy(b, "Time Out ");
  recv(sock, a, sizeof(a), 0);
  f = atoi(a);
  while (1) {
    for (i = 0; i < W; i++) {
      recv(sock, a, sizeof(a), 0);
      if (strcmp(a, b) == 0) {
        break;
      }
    }
    i = 0;
    while (i < W) {
      j = rand() % P1;
      if (j < P2) {
        send(sock, b, sizeof(b), 0);
        break;
      } else {
        alpha9(c);
        if (c <= f) {
          printf("\nFrame %s Received ", a);
          send(sock, a, sizeof(a), 0);
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
  close(sock);
  close(s);
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
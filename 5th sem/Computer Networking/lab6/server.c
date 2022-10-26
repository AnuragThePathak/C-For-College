// server code for UDP socket programming
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define IP_PROTOCOL 0
#define PORT_NO 15050
#define NET_BUF_SIZE 32
#define cipherKey 'S'
#define sendrecvflag 0
#define nofile "File Not Found!"

// function to clear buffer
void clearBuf(char *b) {
  int i;
  for (i = 0; i < NET_BUF_SIZE; i++)
    b[i] = '\0';
}

// function to encrypt
char Cipher(char ch) { return ch ^ cipherKey; }

// function sending file
int sendFile(FILE *fp, char *buf, int s) {
  int i, len;
  if (fp == NULL) {
    strcpy(buf, nofile);
    len = strlen(nofile);
    buf[len] = EOF;
    for (i = 0; i <= len; i++)
      buf[i] = Cipher(buf[i]);
    return 1;
  }

  char ch, ch2;
  for (i = 0; i < s; i++) {
    ch = fgetc(fp);
    ch2 = Cipher(ch);
    buf[i] = ch2;
    if (ch == EOF)
      return 1;
  }
  return 0;
}

// driver code
int main() {
  int sockfd, nBytes, new_socket;
  struct sockaddr_in addr_con;
  socklen_t addrlen = sizeof(addr_con);
  int opt = 1;
  char net_buf[NET_BUF_SIZE];
  FILE *fp;

  // socket()
  if ((sockfd = socket(AF_INET, SOCK_STREAM, IP_PROTOCOL)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  if (sockfd < 0)
    printf("\nfile descriptor not received!!\n");
  else
    printf("\nfile descriptor %d received\n", sockfd);

  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  addr_con.sin_family = AF_INET;
  addr_con.sin_port = htons(PORT_NO);
  addr_con.sin_addr.s_addr = INADDR_ANY;

  // bind()
  if (bind(sockfd, (struct sockaddr *)&addr_con, sizeof(addr_con)) == 0)
    printf("\nSuccessfully binded!\n");
  else
    printf("\nBinding Failed!\n");

  if (listen(sockfd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while (1) {
    printf("\nWaiting for file name...\n");

    // receive file name
    clearBuf(net_buf);

    if ((new_socket = accept(sockfd, (struct sockaddr *)&addr_con,
                             (socklen_t *)&addrlen)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }
    
    nBytes = read(new_socket, net_buf, NET_BUF_SIZE);

    fp = fopen(net_buf, "r");
    printf("\nFile Name Received: %s\n", net_buf);
    if (fp == NULL)
      printf("\nFile open failed!\n");
    else
      printf("\nFile Successfully opened!\n");

    while (1) {

      // process
      if (sendFile(fp, net_buf, NET_BUF_SIZE)) {

        send(new_socket, net_buf, NET_BUF_SIZE, sendrecvflag);
        break;
      }

      // send
      send(new_socket, net_buf, NET_BUF_SIZE, sendrecvflag);
      clearBuf(net_buf);
    }
    if (fp != NULL)
      fclose(fp);
  }
  return 0;
}

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main() {
  int server_fd, new_socket;
  long valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);

  char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  memset(address.sin_zero, '\0', sizeof address.sin_zero);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Socket binding failed");
    exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 10) < 0) {
    perror("Socket listening failed");
    exit(EXIT_FAILURE);
  }
  FILE *htmlData = fopen("index.html", "r");
  char line[100];
  char responseData[8000];
  while (fgets(line, 100, htmlData) != 0) {
    strcat(responseData, line);
  }
  strcat(httpHeader, responseData);
  fclose(htmlData);
  
  while (1) {
    printf("\n+++++++ Waiting for new connection ++++++++\n\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
      perror("Socket accept failed");
      exit(EXIT_FAILURE);
    }

    char buffer[30000] = {0};
    valread = read(new_socket, buffer, 30000);
    printf("%s\n", buffer);
    write(new_socket, httpHeader, strlen(httpHeader));
    printf("------------------Request served-------------------");
    close(new_socket);
  }
  return 0;
}
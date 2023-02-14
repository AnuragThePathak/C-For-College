#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#define MAX 1024
#define SIZE 1024
#define PORT 8080

void recv_file(int sockfd, struct sockaddr_in addr)
{

    int n;
    char buffer[SIZE];
    socklen_t addr_size;
    while (1)
    {
        addr_size = sizeof(addr);
        n = recvfrom(sockfd, buffer, SIZE, 0, (struct sockaddr *)&addr, &addr_size);

        if (strcmp(buffer, "END") == 0)
        {
            break;
        }
        printf("%s", buffer);
        bzero(buffer, SIZE);
    }
}

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    char buffer[MAX], message[MAX];
    struct sockaddr_in cliaddr, srv_addr;
    socklen_t addr_len = sizeof(srv_addr);

    bzero(&srv_addr, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    srv_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

    while (1)
    {
        printf("\nType the command to execute : ");
        fgets(buffer, sizeof(buffer), stdin);
        sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&srv_addr, addr_len);
        if (strcmp(buffer, "end\n") == 0)
        {
            close(sockfd);
            exit(0);
        }
        recv_file(sockfd, srv_addr);
    }
    return 0;
}
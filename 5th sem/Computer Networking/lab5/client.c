#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    while(1){
        int len;
        unsigned long long int num,fact,n;
        scanf("%llu",&num);
        sendto(sockfd, &num, sizeof(num),
            MSG_CONFIRM, (const struct sockaddr *)&servaddr,
            sizeof(servaddr));
        n = recvfrom(sockfd, &fact, sizeof(fact),
                    MSG_WAITALL, (struct sockaddr *)&servaddr,
                    &len);
        printf("Factorial of %llu is %llu\n",num, fact);
        
    }
    close(sockfd);
    return 0;
}
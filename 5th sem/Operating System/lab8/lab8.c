#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <error.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
    int pfd[2];
    if (pipe(pfd) == -1)
    {
        return -1;
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("child creation failed");
        exit(1);
    }
    if (pid == 0)
    {
        dup2(pfd[1], STDOUT_FILENO);
        close(pfd[0]);
        close(pfd[1]);
        execlp("who", "who", (char *)(NULL));
    }
    else
    {
        wait(NULL);
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[0]);
        close(pfd[1]);
        execlp("wc", "wc", "-l", (char *)(NULL));
    }

    return 0;
}
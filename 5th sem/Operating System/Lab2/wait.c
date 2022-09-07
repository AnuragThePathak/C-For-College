#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_info(int id1, int id2)
{
    printf("child\n");
    printf("id1=%d, id2=%d\n", id1, id2);
    printf("pid=%d\n", getpid());
    printf("parent id=%d\n", getppid());
}

void parent_info(int id1, int id2)
{
    printf("parent\n");
    printf("id1=%d, id2=%d\n", id1, id2);
    printf("pid=%d\n", getpid());
}

int main()
{
    pid_t id1 = fork();
    pid_t id2 = fork();

    if (id1 > 0 && id2 > 0)
    {
        wait(NULL);
        parent_info(id1, id2);
    }
    else if (id1 == 0 && id2 > 0)
    {
        child_info(id1, id2);
    }
    else if (id1 > 0 && id2 == 0)
    {
        child_info(id1, id2);
    }
    else if (id1 == 0 & id2 == 0)
    {
        child_info(id1, id2);
    }

    return 0;
}

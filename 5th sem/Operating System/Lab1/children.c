#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

int count = 0;

int main()
{
    int n1 = fork();
    count++;
    int n2 = fork();
    count += 2;

    if (n1 > 0 && n2 > 0)
    {
        printf("parent\n");
        printf("%d %d \n", n1, n2);
        printf("id is %d \n", getpid());
        printf("parent id is %d \n", getppid());
    }
    else if (n1 == 0 && n2 > 0)
    {
        printf("First child\n");
        printf("%d %d \n", n1, n2);
        printf("id is %d \n", getpid());
        printf("parent id is %d \n", getppid());
    }
    else if (n1 > 0 && n2 == 0)
    {
        printf("Second child\n");
        printf("%d %d \n", n1, n2);
        printf("id is %d \n", getpid());
        printf("parent id is %d \n", getppid());
    }
    else
    {
        printf("third child\n");
        printf("%d %d \n", n1, n2);
        printf("id is %d \n", getpid());
        printf("parent id is %d \n", getppid());
    }
    printf("Count of processes is : %d \n", count);
    return 0;
}

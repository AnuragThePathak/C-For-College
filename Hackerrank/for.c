#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    char *name[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"};
    for (int i = a; i <= b; i++)
    {
        if (i < 10)
        {
            printf("%s\n", *(name + i - 1));
        }
        else if (i % 2)
        {
            printf("odd\n");
        }
        else
        {
            printf("even\n");
        }
    }
    return 0;
}
#include <stdio.h>

int main()
{
    int n, i;
    printf("Input length of string:");
    scanf("%d", &n);
    int ar[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("The array in reverse order is\n");
    for(i=n-1; i>=0; i--)
    {
        printf("%d ",*(ar+i));
    }
    printf("\n");
    return 0;
}
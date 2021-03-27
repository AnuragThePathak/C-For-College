#include <stdio.h>

int findMax(int n, int ar[])
{
    int i, j = ar[0];
    for (i = 0; i < n; i++)
    {
        if (j < ar[i])
        {
            j = ar[i];
        }
    }
    return j;
}
int findMin(int n, int ar[])
{
    int i, j = ar[0];
    for (i = 0; i < n; i++)
    {
        if (j > ar[i])
        {
            j = ar[i];
        }
    }
    return j;
}
void ascend(int n, int ar[])
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                k = ar[i];
                ar[i] = ar[j];
                ar[j] = k;
            }
        }
    }
}
int main()
{
    int n, i;
    printf("Input length of string:");
    scanf("%d", &n);
    int ar[n];
    printf("Input the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("The maximum element is %d\n", findMax(n, ar));
    printf("The minimum element is %d\n", findMin(n, ar));
    ascend(n, ar);
    printf("The array in ascending order is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
    return 0;
}
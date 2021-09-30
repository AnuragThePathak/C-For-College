#include <stdio.h>

int secondMax(int *arr, int n)
{
    int max = *arr;
    int second = *arr;
    for (int i = 1; i < n; i++)
    {
        if (max < *(arr + i))
        {
            second = max;
            max = *(arr + i);
        }
    }
    return second;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", secondMax(arr, n));
    return 0;
}

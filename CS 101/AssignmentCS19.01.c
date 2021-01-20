#include <stdio.h>

int main()
{
    int n,i;
    printf("enter the number:");
    scanf("%d",&n);
    // using array
    int ar[10];
    for (i = 0; n>0; i++)
    {
        ar[i]=(n%2);
        n=(n/2);
    }
    printf("The number in binary system is:");
    for (i =(i-1); i>=0; i--)
    {
        printf("%d",ar[i]);
    }
    
    
    return 0;
}
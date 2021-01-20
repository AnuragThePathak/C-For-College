#include <stdio.h>

int main()
{
    printf("First one\n");
    int n;
    printf("enter number of natural numbers:");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n",i);
    }

    printf("3rd one\n");
    int ar1[]={1,2,3,4,5};
    for (int i = 1; i <=5; i++)
    {
        printf("ar1[%d]=%d\n",i-1,ar1[i-1]);
    }
    
    int ar[5];
    printf("4th one\n");
    int ar2[]={6,7,8,9,4};
    for(int i=0;i<5;i++)
    {
        ar[i]=ar1[i]+ar2[i];
        printf("ar[%d]=%d\n",i,ar[i]);
    }

    // the following portion is not correct
    printf("5th one\n");
    int j,k;
    ar1[j]=ar2[k];
    printf("%d\n",ar1[j]);
    printf("%d\n",ar2[k]);
    return 0;
}
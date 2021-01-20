#include <stdio.h>

int main()
{
    int len, bre, hei;
    printf("enter the value of length:");
    scanf("%d",&len);
    printf("enter the value of breadth:");
    scanf("%d",&bre);
    printf("enter the value of height:");
    scanf("%d",&hei);

    printf("the volume of the cuboid is :%d",len*bre*hei);
    return 0;
}
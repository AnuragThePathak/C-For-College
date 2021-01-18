#include <stdio.h>

int main()
{
    int a,b,c;
    printf("enter the value of a:");
    scanf("%d",&a);
    printf("enter the value of a:");
    scanf("%d",&b);
    printf("enter the value of a:");
    scanf("%d",&c);

    // for maximum
    if ((a>b)&&(a>c))
    {
        printf("%d\n\n",a);
    }
    else if (b>c)
    {
        printf("%d\n\n",b);
    }
    else
    {
        printf("%d\n\n",c);
    }

    // for minimum
    
    if ((a<b)&&(a<c))
    {
        printf("%d\n",a);
    }
    else if (b<c)
    {
        printf("%d\n",b);
    }
    else
    {
        printf("%d\n",c);
    }
    return 0;
}
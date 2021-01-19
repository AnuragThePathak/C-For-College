#include <stdio.h>

int main()
{
    int a=3, b=5;

    printf ("1st part\n");
    int c;
    c=a;
    a=b;
    b=c;
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    printf("3nd part\n");
    a=3,b=5;
    a=(a+b);//a=8
    b=(a-b);//b=(8-5=3)
    a=(a-b);
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    printf("2nd part\n");
    a=3,b=5;
    a=(a*b);//a=5*3=15
    b=(a/b);//15/5=3
    a=(a/b);//15/3=5
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    //part 4
    printf("volume of a cylinder\n");
    float r,h;
    printf("Enter value of radius and height respectively ");
    scanf("%f",&r);
    scanf("%f",&h);
    float sq=(r,2);
    printf("Volume=%f", (3.14*sq*h));
    //instead of r*r we can use sq now

    return 0;
}

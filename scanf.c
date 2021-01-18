#include <stdio.h>

int main()
{
    float a, b, sum, sub, mul, div, mod;
    printf("enter thre value of a:");
    scanf("%f",&a);
    printf("enter the value of b:");
    scanf("%f",&b);
    sum=(a+b);
    sub=(a-b);
    mul=(a*b);
    div=(a/b);
    printf("sum of %f & %f is %f",a,b,sum);
    printf("\nsub of %f & %f is %f",a,b,sub);
    printf("\nmultiplication of %f & %f is %f",a,b,mul);
    printf("\nndivision of %f & %f is %f",a,b,div);

    return 0;
}

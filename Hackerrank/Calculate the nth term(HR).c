#include <stdio.h>

int a, b, c;
int nthTerm(int n)
{
    if (n==1)
    {
        return a;
    }
    else if (n==2)
    {
        return b;
    }
    else if (n==3)
    {
        return c;
    }
    return (nthTerm(n-1)+nthTerm(n-2)+nthTerm(n-3));
}
int main()
{
    int n;
    scanf("%d %d %d %d",&n, &a, &b, &c);
    printf("%d", nthTerm(n));
    return 0;
}
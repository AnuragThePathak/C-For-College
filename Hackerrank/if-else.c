#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    char* name[]={
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    if(n<10)
    {
    printf("%s", *(name+n-1));
    }
    else{
        printf("Greater than 9");
    }
    return 0;
}
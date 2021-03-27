#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr=NULL;
    ptr= (int*)malloc(4*sizeof(int));
    for (int i = 0; i < 4; i++)
    {
        *(ptr+i)=i+10;
    }
    
    for (int i = 0; i < 4; i++)
    {
        printf("%d ",*(ptr+i));
    }
    printf("\n");
    return 0;
}
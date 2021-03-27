#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* num;
    int i;
    num= (char*)malloc(1000*1);
    int* count=NULL;
    count= (int*)calloc(10, sizeof(int));
    scanf("%s",num);
    num=(char*)realloc(num, (strlen(num)+1)*sizeof(char));
    for (i = 0; i < strlen(num); i++)
    {
        if ((num[i]<=57)&&(num[i]>=48))
        {
            count[num[i]-48]++;
        }   
    }
    for (i = 0; i < strlen(num); i++)
    {
        printf("%d ",count[i]);
    }
    
    free(count);
    return 0;
}
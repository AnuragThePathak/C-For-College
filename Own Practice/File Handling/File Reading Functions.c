#include <stdio.h>

int main()
{
    FILE* ptr=NULL;
    ptr=fopen("fileManage.txt", "r");
    // char string[5000];
    // fscanf(ptr, "%[^\n]s", string);
    // // char string[5];
    // // fscanf(ptr, "%s", string);
    // printf("%s\n", string);

    // printf("**** all with exact memory use ****\n");
    // char c;
    // while(c !=EOF)
    // {
    //     c=getc(ptr);
    //     printf("%c",c);
    // }
    // printf("\n");

    char string[3];
    fgets(string, 4, ptr);
    printf("%s\n", string);
    fclose(ptr);
    return 0;
}
#include <stdio.h>

int main()
{
    FILE* ptr=NULL;
    ptr=fopen("fileManage.txt","r");
    int out;
    // //***using fscanf ***
    // char string[200];
    // fscanf(ptr, "%s", string);
    // printf("%s",string);

    //***using fgetc***
    out=fgetc(ptr);
    while(out !=EOF)
    {
        printf("%c",out);
        out=fgetc(ptr);
    }

    // //*** using fgets ***
    // printf("%s\n",fgets(out,400,ptr));
    printf("\n");
    fclose(ptr);
    return 0;
}
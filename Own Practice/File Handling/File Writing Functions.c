#include <stdio.h>

int main()
{
    FILE* ptr=NULL;
    ptr=fopen("File Writing.txt","w");
    fprintf(ptr, "This is starting.");
    char string[25]=" Continued writing.";
    fprintf(ptr, "%s", string);
    char string1[25]= " Stopped using fprintf.\n";
    fputs(string1, ptr);
    fputs("Tring to make it better like that.",ptr);
    char c='a';
    fputc(c, ptr);
    fputc('s', ptr);
    fclose(ptr);
    return 0;
}
#include <stdio.h>

int main()
{
    FILE* ptr;
    ptr= fopen("r+ mode.txt", "r+");
    
    fprintf(ptr, "top");
    //if we try reading after writing then newly written part doesn't appear in reading
    // char string[4];
    // fgets( string,5,ptr);
    // printf("%s\n", string);
    fclose(ptr);
    return 0;
}
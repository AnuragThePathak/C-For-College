#include <stdio.h>
#include <string.h>
int main()
{
    char string[100];
    gets(string);
    char string1[100];
    int i;
    gets(string1);
    int len  = strlen(string);
    int j;
    string[len+1] = ' ';
    
    for (j = 0; string1[j] != '\0'; ++j, ++len) {
    string[len] = string1[j];
  }
    string[len]='\0';
    printf("%s",string);
    return 0;
}

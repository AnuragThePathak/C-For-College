#include <stdio.h>
#include <string.h>
// #include <iostream.h>

int main()
{
    char string[100];
    gets(string);
    // scanf("%[^\n]s",string);
    // for (int i = 0; i < 100; i++)
    // {
    //     /* code */
    //     if((string[i]>='a')&&(string[i]<='z')){
    //         string[i]=string[i]+'A'-'a';
    //     }
    // }
    // puts(string);
    // printf("%d",'\0');

    // int j;
    // for(j = 1; string[j]!='\0'; ++j); //because \0 is 0
    // printf("%d\n",j);

    char string1[100];

    // gets(string1);
    // static int k=0;
    // for (int i = j-1; i >=0; i--)
    // {
    //     /* code */
    //     string1[k]=string[i];
    //     k++;
    // }
    // puts(string1);
    int i;
    gets(string1);
    char string2[200];
    for (i = 0; i < strlen(string); i++)
    {
        /* code */
        string2[i]=string[i];
    }
    
    string2[i+1]=' ';i++;
    int m;
    printf("%d\n",i);
    for (int j=0;j<strlen(string1);j++)
    {
        /* code */
        string2[i]=string1[j];
        i++;
    }
    string2[i]='\0';
    puts(string2);
    return 0;
}
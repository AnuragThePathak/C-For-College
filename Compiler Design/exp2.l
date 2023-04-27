%{
#include <stdio.h>
%}

%%

int|float|double|char      printf("Keyword: %s\n", yytext);
if|else|while|for|break|continue          printf("Keyword: %s\n", yytext);
[+\-*/]                     printf("Operator: %s\n", yytext);
[=><!]=?                    printf("Operator: %s\n", yytext);
[a-zA-Z_][a-zA-Z0-9_]*                  printf("Symbol: %s\n", yytext);
[ \t\n]                     /* ignore whitespace */
.                           /* ignore anything else */

%%

int main() {
    yylex();
    return 0;
}

%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*  printf("Identifier: %s\n", yytext);
[+%-*/]                 printf("Operator: %s\n", yytext);
[=><!]=?                printf("Operator: %s\n", yytext);
[ \t\n]                     /* ignore whitespace */
.                           /* ignore anything else */
%%

int main(void) {
	yyin = fopen("in.c","r");
    yylex();
    return 0;
}

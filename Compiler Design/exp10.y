%{
    #include <stdio.h>    
    #include <stdlib.h>
%}

%token DIGIT LETTER NL UND

%%
start: variable NL {printf ("\nValid Variable Name\n"); exit (0);} ;
variable: LETTER alnum ;
alnum: LETTER alnum
| DIGIT alnum 
| UND alnum
| LETTER
| DIGIT
| UND
;
%%

int yyerror (char *msg) {
    printf ("\Invalid Variable Name\n");
    exit (0);
}

int main () {
    printf ("Enter variable name: ");
    yyparse ();
}

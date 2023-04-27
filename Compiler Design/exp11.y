%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%token A B NL

%%
start: string NL {printf ("Valid string\n"); exit (0);} ;
string: A string B | ;
%%

int yyerror (char *msg) {
    printf ("Inavlid string\n");
    exit (0);
}

int main () {
    printf ("Enter a string: ");
    yyparse ();
}

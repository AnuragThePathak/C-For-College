%{
    #include <stdio.h>
    #include <stdlib.h>
    int commentCount = 0;
    FILE *out;
%}
%s commentText
%%
"/*" {BEGIN commentText;}
<commentText>"*/" {BEGIN 0; ++commentCount;}
<commentText>\n {}
<commentText>. {}
"//".* {++commentCount;}
.|\n {fprintf (out, "%s", yytext);}
%%
int yywrap(){
    return 1;
}
int main(){
    yyin = fopen("in.c", "r");
    out = fopen("out.c", "w");
    yylex();
    printf ("NUMBER OF COMMENTS = %d\n", commentCount);
    fclose (out);
    return 0;
}
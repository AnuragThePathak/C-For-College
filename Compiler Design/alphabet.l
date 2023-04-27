%{
int len=0;
%}

%%
[a-zA-Z]+ {printf("Only alphabets are there.");}

.* {printf("Character other than alphabets are also there."); }
%%

int yywrap() { }

int main()
{
yylex();
return 0;
}


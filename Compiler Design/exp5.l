%{
int line_count = 0;
int word_count = 0;
int letter_count = 0;
int special_count = 0;
%}

%%

[\n]            {line_count++;}
[a-zA-Z]+       { word_count++; letter_count += yyleng; }
[0-9]
[" "]
.               { special_count++; }


%%

int main() {
    yylex();
    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of letters: %d\n", letter_count);
    printf("Number of special characters: %d\n", special_count);
    return 0;
}

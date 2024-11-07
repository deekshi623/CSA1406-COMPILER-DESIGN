%{
#include <stdio.h>
%}

%%
[A-Z]+  { printf("Capital word found: %s\n", yytext); }
[a-zA-Z]+  { /* Ignore other words */ }
.    { /* Ignore other characters */ }
%%
int yywrap(){}
int main() {
    yylex();
    return 0;
}

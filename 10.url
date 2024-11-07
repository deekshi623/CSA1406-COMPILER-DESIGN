%{
#include<stdio.h>
%}
%%
[http://]+[www.]+[a-z]+".com" {printf("\n valid url\n");}
.+ {printf("\n invalid url\n");}
%%
int yywrap()
{}
int main()
{
printf("enter url:\n");
yylex();
}

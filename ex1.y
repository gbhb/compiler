%{
#include <stdio.h>
#include <stdlib.h>
#include "ex1.tab.h"
int yylex();
%}
%token INUMBER
%left '+' '-'
%left '*' '/'
%nonassoc NM
%%
program:
|program expr {printf("the result is : %d\n",$2);} 
;
expr :
INUMBER { $$ = $1;}
| expr '+' expr { $$ = $1 + $3;}
| expr '-' expr { $$ = $1 - $3;}
| expr '*' expr { $$ = $1 * $3;}
| expr '/' expr { $$ = $1 / $3;}
| '-' expr %prec NM { $$ = -$2; }
| '(' expr ')' { $$ = $2; }
;
%%
int main()
{
yyparse();
return 0;
}

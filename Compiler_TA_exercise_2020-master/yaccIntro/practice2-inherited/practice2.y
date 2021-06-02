%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
%}
%union{
int ival;
char* word;
}
%token<ival> INUMBER
%token<word> WORD
%type<ival> integer
%type<word> test
%%
line :test test integer { printf("first:%s second: %s\n%d",$1,$2,$3); return(0); }
     ;
test : WORD { $$ = $1; } 
     ;
integer :INUMBER { $$ = $1; } 
          ;
%%
void yyerror(const char *message)
{	
	fprintf(stderr, "%s\n",message);
}
int main(int argc, char *argv[])
{
    yyparse();
    return(0);
}

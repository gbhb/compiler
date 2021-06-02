%{ 
/* Definition section */
#include<stdio.h> 
#include "a.tab.h" 
extern int yylval; 
%}

/* Rule Section */
%% 
[-]?[0-9]+"."[0-9]+  { sscanf(yytext,"%f",&yylval); return NUMBER; }
[-]?[0-9]+   { sscanf(yytext,"%f",&yylval); return NUMBER; }
<<EOF>> { return 0;}
[ \t]   ;
[\n]   ;
.   { return yytext[0]; }

%% 

int yywrap() 
{ 
return 1; 
} 

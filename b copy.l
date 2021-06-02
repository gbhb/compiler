%{ 
/* Definition section */
#include<stdio.h> 
#include "y.tab.h" 
extern int yylval; 
%}

/* Rule Section */
%% 
"<true/>" return TRUE ;
"<false/>" return FALSE ;

"<and>" return ANDS ;
"</and>" return ANDE ;

"<or>" return ORS ;
"</or>" return ORE ;

"<not>" return NOTS ;
"</not>" return NOTE ;

[ \t\n] ; 

. return yytext[0]; 

%% 

int yywrap() 
{ 
return 1; 
} 

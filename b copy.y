%{ 
/* Definition section */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int result;

void yyerror(const char *);


%}

%token  TRUE FALSE
%token  ANDS ANDE
%token  ORS ORE
%token  NOTS NOTE

/* Rule Section */
%% 
stmt:
    expr {result=$1;}
    ;

expr:
    ANDS andexpr ANDE {$$=$2;}
    |ORS orexpr ORE {$$=$2;}
    |NOTS expr NOTE {$$=!$2;}
    |term {$$=$1;}
    ;
andexpr:
    expr andexpr{$$=$1 && $2;}
    |{$$=1;}
    ;
orexpr:
    expr orexpr{$$=$1 || $2;}
    |{$$=0;}
    ;

term:
    TRUE {$$=1;}
    |FALSE {$$=0;}
    ;

%% 
//driver code 
int main(void) 
{ 

yyparse(); 
if(result == 1)
    printf("%s\n","true");
if(result == 0)
    printf("%s\n","false");
// printf("%s\n","false\0true" + result*6);
return 0;
}


void yyerror(const char* msg)
{
    fprintf(stderr,"%s\n",msg);
}



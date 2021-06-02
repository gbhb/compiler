%{
#include <stdio.h>
#define YYSTYPE float
void yyerror(char* msg);
extern int yylex();
float result;
int t=0;
%}

%token NUMBER

%left '+' '-'

%left '*' '/'

%%
p: E { 
		
		result=$$;
        
		}; 
 E:E E '+' {$$=$1+$2;} 
  
 |E E '-' {$$=$1-$2;}  
  
 |E E '*' {$$=$1*$2;}  
  
 |E E '/' {$$=$1/$2;}  
    
 | NUMBER {$$=$1;}  
  ;

%%
void yyerror(char* msg)
{
    printf("Wrong Formula\n") ;
    t=1;
}
int main(int argc, char** argv)
{
    yyparse();
    if(result>10){
    result =result*10;
    int i = (int)(result + 0.5);
    result = i;
    result =result/ 10;
    }
    if(t!=1)
    printf("%.1f\n",result);
    return 0;
}



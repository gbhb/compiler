%{ 
/* Definition section */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char preorder[1000] = {};
int result=0;
char *stack[1000];
int stack_top = 0;
void yyerror(const char *);

void push(const char const * str) {
    int len = strlen(str) + 1;
    stack[stack_top] = malloc(len);
    memcpy(stack[stack_top], str, len);
    stack_top++;
}
%}

%token NUMBER 

%left '+' '-'

%left '*' '/'

%left '(' ')'

/* Rule Section */
%% 

ArithmeticExpression: E{ 
		
		result=$$; 

		return 0; 

		}; 
 E:E'+'E {$$=$1+$3;push("+");} 
  
 |E'-'E {$$=$1-$3;push("-");}  
  
 |E'*'E {$$=$1*$3;push("*");}  
  
 |E'/'E {$$=$1/$3;push("/");}  
  
 |'('E')' {$$=$2;}  
  
 | NUMBER {$$=$1;char str[10]="";sprintf(str,"%d",$1);push(str);}  
  
; 

%% 
int is_operator(char* str) {
    return str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/';
}
void print_preorder(char* str) {
    if(!stack_top) return;
    if(!is_operator(stack[stack_top - 1])) {
        strcat(str, stack[--stack_top]);
        
        return;
    }

    strcat(str, " ");
    strcat(str, stack[--stack_top]);    // pop operator from stack
    

    char op2[256] = " ";
    char op1[256] = " ";

    print_preorder(op2);
    print_preorder(op1);

    strcat(str, op1);
    strcat(str, op2);
}

//driver code 
int main(int argc, char** argv) 
{ 

yyparse(); 

print_preorder(preorder);

printf("the preorder expression is :%s\n", preorder);

printf("the result is : %d\n",result);
return 0;
}


void yyerror(const char* msg)
{
printf("error\n") ;

}



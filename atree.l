%{
typedef struct node {
    int is_operator;
    char val[10];
    struct node* op1;
    struct node* op2;
} node;

node* new_node(char* operator, node* op1, node* op2);

#define YYSTYPE node*
#include "a.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+ {
    yylval = new_node(yytext, NULL, NULL);
    return NUMBER; 
}

[ \t] ;

\n return '\n';

. return yytext[0];

%%

int yywrap() {
    return 1;
}
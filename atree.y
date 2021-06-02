%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE node*
extern int yylex();
void yyerror(char const *);

typedef struct node {
    int is_operator;
    char val[10];
    struct node* op1;
    struct node* op2;
} node;

node* new_node(char* operator, node* op1, node* op2) {
    node* n = malloc(sizeof(node));
    n->is_operator = operator[0] == '+' || operator[0] == '-' || operator[0] == '*' || operator[0] == '/';
    strcpy(n->val, operator);
    n->op1 = op1;
    n->op2 = op2;
    return n;
}

node* tree;

%}

%token NUMBER

%%
line:
    addexpr { tree = $1; return 0; }
    ;

addexpr:
    mulexpr { $$ = $1; }
    | addexpr '+' mulexpr { $$ = new_node("+", $1, $3); }
    | addexpr '-' mulexpr { $$ = new_node("-", $1, $3); }
    ;

mulexpr:
    term { $$ = $1; }
    | mulexpr '*' term { $$ = new_node("*", $1, $3); }
    | mulexpr '/' term { $$ = new_node("/", $1, $3); }
    ;

term:
    NUMBER { $$ = $1; }
    | group { $$ = $1; }
    ;

group:
    '(' addexpr ')' { $$ = $2; }
    ;

%%

void print_preorder(node* n) {
    if(!n) return;
    printf(" %s", n->val);
    print_preorder(n->op1);
    print_preorder(n->op2);
}

int result(node* n) {
    if(!n) return 0;
    if(!n->is_operator) return atoi(n->val);
    int op1 = result(n->op1);
    int op2 = result(n->op2);
    int result;
    switch(n->val[0]) {
        case '+': result = op1 + op2; break;
        case '-': result = op1 - op2; break;
        case '*': result = op1 * op2; break;
        case '/': result = op1 / op2; break;
    }
    return result;
}

int main(void) {
    yyparse();

    printf("the preorder expression is :");
    print_preorder(tree);
    printf("\nthe result is : %d\n", result(tree));

    return 0;
}

void yyerror(char const *s) {
    fprintf(stderr, "%s\n", s);
}
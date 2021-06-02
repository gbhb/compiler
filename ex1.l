%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex1.tab.h"
char save[99] = "";
char preorder[99] = "";
void pre(char input[]);
void Infix_to_Prefix(char str[]);
void Prefix(char *str, char *new_str);
int compare(char op);
void reverse(char str[]);
%}
%option noyywrap
%%
[0-9]+ { yylval = atoi(yytext); strcat(save,yytext) ; return INUMBER; }
[\+\-\*\/\(\)] {strcat(save,yytext); return *yytext; }
<<EOF>> {pre(save);return *yytext;}
. {}
%%
void pre(char input[]){
	Infix_to_Prefix(input);
}
void Infix_to_Prefix(char str[]) {
  char new_str[99] = {"\0"};
  Prefix(str, new_str);
  reverse(new_str);
  printf("the preorder expression is : %s\n", new_str);
}
void Prefix(char *str, char *new_str) {
  char stack[99];
  int top = 0, j = 0, i;
  for (i = strlen(str) - 1; i >= 0; i--) {
    switch (str[i]) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
      while (compare(str[i]) < compare(stack[top])) {
        new_str[j++] = ' ';
        new_str[j++] = stack[top--];
      }
      stack[++top] = str[i];
      continue;
    case ')':
      stack[++top] = str[i];
      continue;
    case '(':
      while (stack[top] != ')') {
        new_str[j++] = ' ';
        new_str[j++] = stack[top--];
      }
      top--;
      continue;
    default:
      if(new_str[j-1]==48 && str[i]==49 );
      else new_str[j++] = ' ';
      new_str[j++] = str[i];
      continue;
    }
  }
  while (top != 0) {
    new_str[j++] = ' ';
    new_str[j++] = stack[top--];
  }
}
int compare(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
  case '%':
    return 2;
  default:
    return 0;
  }
}
void reverse(char str[]) {
  int i, j;
  char c;
  for (i = 0, j = strlen(str) - 1; i < j; ++i, --j)
    c = str[i], str[i] = str[j], str[j] = c;
}
%{
    #include<iostream>
    #include<cstdlib>
    #include<stack>
    #include "AST.h"
    #include "file.tab.hh"
    extern std::stack<ASTType> operation;
%}
separator  [ \t\n\r]
letter     [a-z]
digit      [0-9]
number     0|[1-9]{digit}*|-[1-9]{digit}*
ID         {letter}({letter}|{digit}|"-")*
bool-val   #[t|f]
%%
<<EOF>>      { return(0); }
{separator}  { }
"mod"        { operation.push(AST_MOD); return(MOD); }
"and"        { operation.push(AST_AND); return(AND); }
"or"         { operation.push(AST_OR); return(OR); }
"not"        { operation.push(AST_NOT); return(NOT); }
"define"     { operation.push(AST_DEF); return(DEFINE); }
"fun"        { operation.push(AST_FUN_EXP); return(FUN); }
"if"         { operation.push(AST_IF); return(IF); }
"print-num"  { operation.push(AST_PNUM); return(PRINT_NUM); }
"print-bool" { operation.push(AST_PBOOL); return(PRINT_BOOL); }
{bool-val}   { if (yytext[1] == 't') yylval.b = true;
               else yylval.b = false;
               return(BOOL); }
{number}     { yylval.num = atoi(yytext); return(NUM); }
{ID}         { yylval.id = strdup(yytext); return(ID); }
"+"          { operation.push(AST_ADD); return(yytext[0]); }
"-"          { operation.push(AST_MINUS); return(yytext[0]); }
"*"          { operation.push(AST_MUL); return(yytext[0]); }
"/"          { operation.push(AST_DIV); return(yytext[0]); }
"="          { operation.push(AST_EQUAL); return(yytext[0]); }
">"          { operation.push(AST_GREATER); return(yytext[0]); }
"<"          { operation.push(AST_SMALLER); return(yytext[0]); }
.            { return(yytext[0]); }
%%
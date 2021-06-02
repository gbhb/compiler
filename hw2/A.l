%{
#include<stdio.h>
int tab=0;
int i;
%}
%option noyywrap

Left    ^.*\{.*$
Right   ^.*\}.*$
QQ      ^\t*.*$
%%
{Left}  {
    for(i=0;i<tab;i++)
        printf("\t");
    for(i=0;i<yyleng;i++)
        if(yytext[i]=='\t')
            continue;
        else break;
    for(;i<yyleng;i++){
        printf("%c",yytext[i]);
    }
    printf("\n");
    // printf("////match %s","Left");
    tab++;
}
{Right} {
    tab--;
    for(i=0;i<tab;i++)
        printf("\t");
    for(i=0;i<yyleng;i++)
        if(yytext[i]=='\t')
            continue;
        else break;
    for(;i<yyleng;i++){
        printf("%c",yytext[i]);
    }
    printf("\n");

    // printf("////match %s","Right");
}
\n  {}
{QQ} {
    for(i=0;i<tab;i++)
        printf("\t");
    for(i=0;i<yyleng;i++)
        if(yytext[i]=='\t')
            continue;
        else break;
    for(;i<yyleng;i++){
        printf("%c",yytext[i]);
    }
    printf("\n");

    // printf("////match %s\n","QQ");
}
%%
int main(){
    //printf("QQ");
    yylex();
    return (0);
}
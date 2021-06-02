%{
%}

%option noyywrap
cap_word   ^[ ]*[A-Z][a-zA-Z]*$
file_int   [0-9]|([1-9][0-9])|([1-9][0-9][0-9])|10([0-1][0-9]|2[0-3])
file_cap   ([k|m|g|t])b
file       ^{file_int}{file_cap}$
ip_int     (?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)
ip         ^{ip_int}\.{ip_int}\.{ip_int}\.{ip_int}$
email_word [0-9a-zA-Z]+
email      ^{email_word}@{email_word}(\.{email_word})+$
sn    ^[-+]?[1-9](\.[0-9]+)?[eE][-+]?[0-9]+$
place       [A-Z][a-z\-\.]+[A-Z]
time       ([0-1][0-9]:[0-5][0-9])|(2[0-3]:[0-5][0-9])
day         \+(([12][0-9][0-9])|(3[0-5][0-9])|(36[0-5])|([1-9][0-9])|([0-9]))[^0-9]
atm         \$(([0-9])|([1-9][0-9])|([1-9][0-9][0-9])|([1-9][0-9][0-9][0-9])|([1-9][0-9][0-9][0-9][0-9])|100000)[^0-9]
%%
{time}  {printf("at ");ECHO;printf("\n");}
{day}    {yytext[strlen(yytext)-1]='\0';   printf("after ");printf("%s days\n",yytext);}
{place}    {printf("at ");ECHO;printf("\n");}
{atm}    {yytext[strlen(yytext)-1]='\0';printf("transfer %s\n",yytext);}

[ ]     ;
.       ;
\n      ;

%%

int main(int argc,char *argv[])
{
   yylex();
   return(0);
}
%option noyywrap

sn    ^[+-]?[1-9](\.[0-9]+)?[eE][+-]?[0-9]+\n

%%

{sn} {ECHO;}
.
\n
%%

int main(int argc,char *argv[])
{
   yylex();
   return(0);
}

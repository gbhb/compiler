%{
    #include "BA3A.tab.h"
    void yyerror(const char *);
%}

%%
[0-9]+ {
    yylval.ival = atoi(yytext);
    return INTEGER;
}

"\\frac" {
    return FRAC;
}

"\n"|"-"|"+"|"{"|"}"|"^" {
    return yytext[0];
}

[ \t]+ {
    ;
}

. {
    yyerror("invalid input");
}

%%
%{
    #include "matrix_calculator_cpp.tab.h"
    void yyerror(const char *);
    int position = 0;
%}

%%
[0-9]+ {
    position += yyleng;
    yylval.ival = atoi(yytext);
    return INTEGER;
}

"^T" {
    position += yyleng;
    return TRANSPOSE;
}

"+"|"-"|"*" {
    position += yyleng;
    yylval.ival = position;
    return yytext[0];
}

"("|")"|"["|"]"|"," {
    position += yyleng;
    return yytext[0];
}

[ \t]+ {
    position += yyleng;
}

\n {
    return yytext[0];
}

. {
    yyerror("invalid input");
}

%%
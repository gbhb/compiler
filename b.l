%{
    #include "b.tab.h"
    void yyerror(const char *);
%}

%%
[0-9]+ {
    yylval.ival = atoi(yytext);
    return INTEGER;
}

\n {
    return yytext[0];
}

"add" {
    return ADD;
}

"sub" {
    return SUB;
}

"mul" {
    return MUL;
}

"mod" {
    return MOD;
}

"inc" {
    return INC;
}

"dec" {
    return DEC;
}

"load" {
    return LOAD;
}
"delete" {
    return DELETE;
}
"switch" {
    return SWITCH;
}
"copy" {
    return COPY;
}
"div" {
    return DIV;
}

[ \t]+ {
    ;
}

. {
}

%%
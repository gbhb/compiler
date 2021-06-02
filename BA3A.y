%code requires {
    #include <iostream>
    #include <iomanip>
    #include <cmath>

    int yylex(void);
    void yyerror(const char *);

    struct Type {
        int ival;
        float fval;
    };
    
    #define YYSTYPE Type  // for cpp and c (bison itself) compatibility
}

/* This section defines the additional function using the data type in
 * `%code requires` section.
*/
%code provides {}

/* declarations */
%token <ival> INTEGER
%type <fval> expr

/* precedences */
%left '+' '-'
%nonassoc FRAC
%right '^'
%nonassoc '{' '}'

%%
line    : expr '\n'  {std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << $1 << std::endl;}
        ;

expr    : expr '+' expr         {$$ = $1 + $3;}
        | expr '-' expr         {$$ = $1 - $3;}
        | expr '^' expr         {$$ = std::pow($1, $3);}
        | FRAC expr expr        {$$ = $2 / $3;}
        | '{' expr '}'          {$$ = $2;}
        | INTEGER               {$$ = (float)$1;}
        ;


%%

void yyerror(const char *message) {
    std::cout << "Invalid format" << std::endl;
}

int main(void) {
    yyparse();
    return 0;
}

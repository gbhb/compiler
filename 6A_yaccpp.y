%{
    #include <iostream>
    
    void yyerror(const char *);
    int yylex(void);
    void semantic_err(const int);
%}

%code requires {
    typedef struct {
        int row;
        int col;
    } matrix_dim;
}

%union {
    int ival;
    matrix_dim md;
}

/* declarations */
%token <ival> INTEGER
%type <md> expr
%type <md> matrix

/* precedences */
%left <ival> '+' '-'
%left <ival> '*'
%right TRANSPOSE

%%
line    : expr '\n'             {std::cout << "Accepted" << std::endl;}
        ;

expr    : expr '+' expr         {
                                    if ($1.row == $3.row && $1.col == $3.col) {
                                        $$ = $1;
                                    }
                                    else {
                                        semantic_err($2);
                                        return 0;
                                    }
                                }
        | expr '-' expr         {
                                    if ($1.row == $3.row && $1.col == $3.col) {
                                        $$ = $1;
                                    }
                                    else {
                                        semantic_err($2);
                                        return 0;
                                    }
                                }
        | expr '*' expr         {
                                    if ($1.col == $3.row) {
                                        $$.row = $1.row;
                                        $$.col = $3.col;
                                    }
                                    else {
                                        semantic_err($2);
                                        return 0;
                                    }
                                }
        | '(' expr ')'          {$$ = $2;}
        | expr TRANSPOSE        {
                                    $$.row = $1.col;
                                    $$.col = $1.row;
                                }
        | matrix
        ;

matrix  : '[' INTEGER ',' INTEGER ']' {
                                    $$.row = $2;
                                    $$.col = $4;
                                }
        ;

%%
void semantic_err(const int col_num) {
    std::cout << "Semantic error on col " << col_num << std::endl;
}

void yyerror(const char *message) {
    std::cerr << message << std::endl;
}

int main(void) {
    yyparse();
    return 0;
}

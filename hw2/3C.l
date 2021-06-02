%{
    #include <string>
    #include <iostream>
    void print_hex(char* yytext)
    {
        std::string str(yytext);
        if (str.at(0) == ' ' || str.at(0) == '\n')
            std::cout << str.substr(1);
        else
            std::cout << str;
    }
%}

%option noyywrap

%%

[ \n]0[xX][0-9a-fA-F]{1,8}[ ]*\n  print_hex(yytext);
^0[xX][0-9a-fA-F]{1,8}[ ]*\n       print_hex(yytext);
.
\n
%%

int main(void)
{
    yylex();
    return 0;
}

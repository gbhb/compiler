%{
    #include <iostream>
    #include <stack>
    #include <stdio.h>

    int yylex(void);
    void yyerror(const char *);

    std::stack<int> s;
%}

/* This section defines the additional function using the data type in
 * `%code requires` section.
*/
%code provides {}

%union{
    int ival;
}

/* declarations */
%token <ival> INTEGER
%token <ival> ADD
%token <ival> SUB
%token <ival> MUL
%token <ival> MOD
%token <ival> DIV
%token <ival> INC
%token <ival> DEC
%token <ival> DELETE
%token <ival> SWITCH
%token <ival> COPY
%token <ival> LOAD

%type <ival> expr

%%
program : lines         {
                                if (s.size() != 1) {
                                std::cout << "Invalid format" << std::endl;
                                exit(0);
                            }
                                else
                                std::cout << s.top() << std::endl;
                        }
lines   : lines line    {;}
        | line          {;}
        ;
line    : expr '\n'     {;}
        | expr          {;}
        | '\n'          {;}
        ;

expr    : LOAD INTEGER  {s.push($2);}
        | ADD           {
            if(s.size()<2){
                                    printf("Invalid format\n");
                                    return 0;
                                }                
                                int a = s.top();
                                s.pop();
                                int b = s.top();
                                s.pop();
                                s.push(a + b);
                            
                        }
        | SUB           {
            if(s.size()<2){
                                    printf("Invalid format\n");
                                    return 0;
                                }                
                                int a = s.top();
                                s.pop();
                                int b = s.top();
                                s.pop();
                                s.push(a - b);
                            
                        }
        | MUL           {
            if(s.size()<2){
                                    printf("Invalid format\n");
                                    return 0;
                                }                
                                int a = s.top();
                                s.pop();
                                int b = s.top();
                                s.pop();
                                s.push(a * b);
                            
                        }
        | MOD           {
            if(s.size()<2){
                                    printf("Invalid format\n");
                                    return 0;
                                }                        
                                int a = s.top();
                                s.pop();
                                int b = s.top();
                                s.pop();
                                s.push(a % b);
                            
                        }
        | INC           {

            if(s.size()<1){
                                    printf("Invalid format\n");
                                    return 0;
                                }                
                                int a = s.top();
                                s.pop();
                                a++;
                                s.push(a);
                            
                        }
        | DEC           {
                            
                                if(s.size()<1){
                                    printf("Invalid format\n");
                                    return 0;
                                }
                                int a = s.top();
                                s.pop();
                                a--;
                                s.push(a);
                            
                        }
        | DELETE        {
            if(s.size()<1){
                                    printf("Invalid format\n");
                                    return 0;
                                }
                                s.pop();
                        }
        | COPY          {   
            if(s.size()<1){
                                    printf("Invalid format\n");
                                    return 0;
                                }    
                                int a = s.top();
                                s.push(a);
                        }
        | SWITCH        {       
                                if(s.size()<2){
                                    printf("Invalid format\n");
                                    return 0;
                                }                                
                                int a = s.top();
                                s.pop();
                                int b = s.top();
                                s.pop();
                                s.push(a);
                                s.push(b);
                        }
        | DIV          {       
                                if(s.size()<2){
                                    printf("Invalid format\n");
                                    return 0;
                                }      
                                int a = s.top();
                                s.pop();
                                int b = s.top();
                                s.pop();
                                if(b==0){
                                    printf("Divide by zero\n");
                                    return 0;
                                }
                                s.push(a / b);
                        }
        ;

%%

void yyerror(const char *message) {
    std::cout << "Invalid format" << std::endl;
}

int main(void) {
    yyparse();
    return 0;
}

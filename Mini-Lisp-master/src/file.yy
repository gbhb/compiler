%{
    #include<iostream>
    #include<cstdlib>
    #include "AST.h"
    #include<map>
    #include<cstring>
    #include<stack>
    #include<vector>
    
    extern int yylex(void);
    void yyerror(const char *msg);
    typedef std::map<std::string, ASTNode *> Map;
    Map* def;
    Map::iterator iter;
    std::stack<ASTType> operation;
    ASTNode *root;
    int ASTArith(ASTNode *, Map *map);
    bool ASTLogical(ASTNode *, Map *map);
    ASTVal* ASTVisit(ASTNode *, Map *map);
    ASTNode* ASTIf_stmt(ASTNode *node, Map *map);
    void ASTDef_stmt(ASTNode *node);
    void print_Result(ASTVal *v);
    bool ASTEqual(ASTNode *node, Map *map);
    ASTNode *find_def(ASTNode *node, Map *map);
    ASTVal* ASTFun_call(ASTNode *fun_exp, ASTNode *par_node);
    ASTNode* two_Node(ASTNode *exp_1, ASTNode *exp2);
    ASTNode* three_Node(ASTNode *exp_1, ASTNode *exp_2, ASTNode *exp_3);
%}

%union {
    bool b;
    int num;
    char *id;
    ASTNode *node;
}
%token<b> BOOL
%token<num> NUM
%token<id> ID
%token MOD AND OR NOT DEFINE FUN IF PRINT_NUM PRINT_BOOL
%type<node> program stmt stmts print_stmt def_stmt exps exp
%type<node> plus minus multiply divid modulus greater smaller equal
%type<node> num_op logical_op fun_exp fun_call fun_ids fun_body if_exp
%type<node> and_op or_op not_op test_exp then_exp else_exp fun_name
%type<node> variable variables params param

%left BOOL NUM ID
%left '+' '-'
%left '*' '/' MOD
%left AND OR NOT
%left '(' ')'
%%
program: stmt stmts {
            operation.push(AST_ROOT);
            $$ = two_Node($1, $2);
            root = $$;
        }
        ;
stmts: stmt stmts {
            operation.push(AST_ROOT);
            $$ = two_Node($1, $2);
        }
         | /* lambda */ { 
            operation.push(AST_NULL);
            $$ = two_Node(NULL, NULL); 
        }
        ;
stmt: exp | def_stmt | print_stmt ;
print_stmt: '(' PRINT_NUM exp ')' { $$ = two_Node($3, NULL); }// two node will get type as parent from stack and set lhs rhs children
          | '(' PRINT_BOOL exp ')' { $$ = two_Node($3, NULL); }
          ;
exps: exp exps {
            $$ = (ASTNode *)malloc(sizeof(ASTNode));
            $$->type = operation.top();
            $$->lhs = $1;
            $$->rhs = $2;
        }
         | /* lambda */ { 
            operation.push(AST_NULL);
            $$ = two_Node(NULL, NULL); 
        }
        ;
exp: BOOL {
            ASTBool *b = (ASTBool *)malloc(sizeof(ASTBool));
            b->type = AST_BOOL;
            b->b = $1;
            $$ = (ASTNode *)b;
        }
        | NUM  {
            ASTNum *num = (ASTNum *)malloc(sizeof(ASTNum));
            num->type = AST_NUM;
            num->num = $1;
            $$ = (ASTNode *)num;
        }
        | variable | num_op | logical_op | fun_exp | fun_call | if_exp;
num_op: plus | minus | multiply | divid | modulus | greater | smaller | equal ;
        plus: '(' '+' exp exp exps ')' { $$ = three_Node($3, $4, $5); }
                ;
        minus: '(' '-' exp exp ')' { $$ = two_Node($3, $4); }
                ;
        multiply: '(' '*' exp exp exps ')' { $$ = three_Node($3, $4, $5); }
                ;
        divid: '(' '/' exp exp ')' { $$ = two_Node($3, $4); }
                ;
        modulus: '(' MOD exp exp ')' { $$ = two_Node($3, $4); }
                ;
        greater: '(' '>' exp exp ')' { $$ = two_Node($3, $4); }
                ;
        smaller: '(' '<' exp exp ')' { $$ = two_Node($3, $4); }
                ;
        equal: '(' '=' exp exp exps ')' { $$ = three_Node($3, $4, $5); }
                ;
logical_op: and_op | or_op | not_op ;
        and_op: '(' AND exp exp exps ')' { $$ = three_Node($3, $4, $5); }
                ;
        or_op: '(' OR exp exp exps ')' { $$ = three_Node($3, $4, $5); }
                ;
        not_op: '(' NOT exp ')' { $$ = two_Node($3, NULL); }
                ;
def_stmt: '(' DEFINE variable exp ')' { $$ = two_Node($3, $4); }
        ;
        variable: ID {
            ASTId *id = (ASTId *)malloc(sizeof(ASTId));
            id->type = AST_ID;
            id->id = (char *)malloc(sizeof(char) * strlen($1));
            id->id = $1;
            $$ = (ASTNode *)id;
        }
        ;
fun_exp: '(' FUN fun_ids fun_body ')' { $$ = two_Node($3, $4); }
        ;
        fun_ids: '(' variables ')' { $$ = $2; }
                ;
        fun_body: exp
                ;
        fun_call: '(' fun_exp params ')'  { 
                    operation.push(AST_FUN_CALL);
                    $$ = two_Node($2, $3);
                }
                | '(' fun_name params ')' {
                    operation.push(AST_FUN_NAME);
                    $$ = two_Node($2, $3);
                }
                ;
        fun_name:variable;
        params: param params {
                    operation.push(AST_NUM);
                    $$ = two_Node($1, $2);
                }
                | /* lambda */ {
                    operation.push(AST_NULL);
                    $$ = two_Node(NULL, NULL);
                }
                ;
        param: exp
                ;
        variables: variable variables {
                    operation.push(AST_ID);
                    $$ = two_Node($1, $2);
                }
                | /* lambda */ { 
                    operation.push(AST_NULL);
                    $$ = two_Node(NULL, NULL); 
                }
                ;
if_exp: '(' IF test_exp then_exp else_exp ')' {
            ASTIf *if_s = (ASTIf *)malloc(sizeof(ASTIf));
            if_s->type = operation.top();
            if_s->mhs = $3;
            if_s->lhs = $4;
            if_s->rhs = $5;
            $$ = (ASTNode *)if_s;
            operation.pop();
        }
        ;
        test_exp: exp
                ;
        then_exp: exp
                ;
        else_exp: exp
                ;
%%
void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(0);
}

ASTNode* two_Node(ASTNode *exp_1, ASTNode *exp_2) {
    ASTNode *reduce = (ASTNode *)malloc(sizeof(ASTNode));
    reduce->type = operation.top();//use stack to get the sequential type and first in last out 
    reduce->lhs = exp_1;
    reduce->rhs = exp_2;
    operation.pop();
    return reduce;
}

ASTNode* three_Node(ASTNode *exp_1, ASTNode *exp_2, ASTNode *exp_3) {
    ASTNode *reduce = (ASTNode *)malloc(sizeof(ASTNode));
    reduce->type = operation.top();
    reduce->lhs = exp_1;
    ASTNode *rhs = (ASTNode *)malloc(sizeof(ASTNode));
    rhs->type = operation.top();
    rhs->lhs = exp_2;
    rhs->rhs = exp_3;
    reduce->rhs = rhs;
    operation.pop();
    return reduce;
}

int ASTArith(ASTNode *node, Map *map) {// here not have bool so if bool return to here will detect error
    int val;
    ASTNum *num = (ASTNum *)node;
    switch(node->type) {
        case AST_ADD:
            val = ASTArith(node->lhs, map) + ASTArith(node->rhs, map);
            if (node->rhs->type == AST_NULL) val--;// because val initail = 1
            break;
        case AST_MINUS:
            val = ASTArith(node->lhs, map) - ASTArith(node->rhs, map);
            break;
        case AST_MUL:
            val = ASTArith(node->lhs, map) * ASTArith(node->rhs, map);
            break;
        case AST_DIV:
            val = ASTArith(node->lhs, map) / ASTArith(node->rhs, map);
            break;
        case AST_MOD:
            val = ASTArith(node->lhs, map) % ASTArith(node->rhs, map);
            break;
        case AST_NUM:
            val = num->num;
            break;
        case AST_GREATER:
            if (ASTArith(node->lhs, map) > ASTArith(node->rhs, map)) val = 1;
            else val = 0;
            break;
        case AST_SMALLER:
            if (ASTArith(node->lhs, map) < ASTArith(node->rhs, map)) val = 1;
            else val = 0;
            break;
        case AST_NULL:
            val = 1;
            break;
        case AST_ID:
            val = ASTVisit(find_def(node, map), map)->num;
            break;
        default:
            // val = ASTVisit(node, map)->num;
            printf("unexpected type: %d\n", node->type); //type check %d is from enum
            puts("syntax error");
            exit(0);
            break;
    }
    return val;
}

bool ASTEqual(ASTNode *node, Map *map) {
    if (node->rhs->type != AST_NULL) {
            /* represent true and false */
        if (ASTArith(node->lhs, map) == ASTArith(node->rhs->lhs, map)) 
            return ASTEqual(node->rhs, map);
        else 
            return false;
    } else {
        return true;
    }
}

bool ASTLogical(ASTNode *node, Map *map) {// here not have num so if num return to here will detect error
    bool b;
    ASTBool *b_s = (ASTBool *)node;
    switch(node->type) {
        case AST_AND:
            b = ASTLogical(node->lhs, map) && ASTLogical(node->rhs, map);//f&f= f&(f&t)= f&(f) 
            break;
        case AST_OR:
            if (node->rhs->type == AST_NULL) {//f|f != f|(f|t) so need if just return lhs
                b = ASTLogical(node->lhs, map);
            } else {
                b = ASTLogical(node->lhs, map) || ASTLogical(node->rhs, map);
            }
            break;
        case AST_NOT:   
            b = !ASTLogical(node->lhs, map);
            break;
        case AST_GREATER:
        case AST_SMALLER:
            if (ASTArith(node, map) == 1) b = true;
            else b = false;
            break;
        case AST_EQUAL:
            b = ASTEqual(node, map);
            break;
        case AST_BOOL:            
            b = b_s->b;
            break;
        case AST_ID:
            b = ASTVisit(find_def(node, map), map)->b;
            break;
        case AST_NULL:
            b = true;
            break;
        default:
            printf("unexpected type: %d\n", node->type);
            puts("syntax error");
            exit(0);
            break;
    }
    return b;
}

ASTNode* ASTIf_stmt(ASTNode *node, Map *map) {
    ASTIf *if_s = (ASTIf *)node;
    if (ASTLogical(if_s->mhs, map)) return if_s->lhs; 
    else return if_s->rhs;
}

void ASTDef_stmt(ASTNode *node) {
    ASTId *id = (ASTId *)node->lhs;
    std::string str(id->id);//str = id->id;
    iter = def->find(str);
    if (iter != def->end()) {
        /* if found -> already defined */
        printf("Redefined id: %s\n", id->id);
        exit(0);
    } else {
        // printf("node->rhs->type: %d\n", node->rhs->type);
        // printf("define: %s\n", id->id);
        (*def)[str] = node->rhs;// Map* def;
    }
}


ASTVal* ASTFun_call(ASTNode *fun_exp, ASTNode *par_node) {
    std::vector<std::string> ids;
    std::vector<ASTNode *> params;
    ASTNode *id_node = fun_exp->lhs;// next floor 
    ASTNode *fun_body = fun_exp->rhs;
    Map* fun_map = new Map();
    if (par_node == NULL) {
        return ASTVisit(fun_body, fun_map);
    }
    if (par_node->type == AST_NULL && id_node->type == AST_NULL) {
        return ASTVisit(fun_body, fun_map);
    }
    while (par_node->type != AST_NULL) {
        ASTNode *n = (ASTNode *)ASTVisit(par_node->lhs, def);
        params.push_back(n);
        par_node = par_node->rhs;
    }
    while (id_node->type != AST_NULL) {
        ASTId *id = (ASTId *)id_node->lhs;
        std::string str(id->id);
        ids.push_back(str);
        id_node = id_node->rhs;
    }
    
    if (params.size() == ids.size()) {
        std::vector<ASTNode *>::iterator pa_it;
        std::vector<std::string>::iterator id_it;
        for (pa_it = params.begin(), id_it = ids.begin(); pa_it != params.end(); ++pa_it, ++id_it) {//fun map is local variable
            (*fun_map)[*id_it] = *pa_it;
        }
    } else {
        puts("number of params and ids do not match");
        exit(0);
    }
    /* fun_body */
    return ASTVisit(fun_body, fun_map);
}

ASTNode *find_def(ASTNode *node, Map *map) {
    ASTId *id = (ASTId *)node;
    std::string str(id->id);
    iter = map->find(str);
    if (iter == map->end()) {
        /* if found -> already defined */
        puts("variable not defined yet. in find_def");
        printf("id->id: %s\n", id->id);
        exit(0);
    }
    return iter->second;
}

ASTVal* ASTVisit(ASTNode *node, Map* map) {
    ASTVal *v = (ASTVal *)malloc(sizeof(ASTVal));
    switch(node->type) {
        case AST_ROOT://type root will right left visit
            ASTVisit(node->lhs, map);
            ASTVisit(node->rhs, map);
            break;
        case AST_ADD:
        case AST_MINUS:
        case AST_MUL:
        case AST_DIV:
        case AST_MOD:
        case AST_NUM:
            v->type = AST_NUM;
            v->num = ASTArith(node, map);
            break;
        case AST_AND:
        case AST_OR:
        case AST_NOT:        
        case AST_GREATER:
        case AST_SMALLER:
        case AST_EQUAL:
        case AST_BOOL:
            v->type = AST_BOOL;
            v->b = ASTLogical(node, map);
            break;
        case AST_ID:
            /* add find id */
            v = ASTVisit(find_def(node, map), map);
            break;
        case AST_PNUM:
            v = ASTVisit(node->lhs, map);
            printf("%d\n", v->num);
            break;
        case AST_PBOOL:
            v = ASTVisit(node->lhs, map);
            printf(v->b ? "#t\n" : "#f\n");
            break;
        case AST_IF:
            v = ASTVisit(ASTIf_stmt(node, map), map);
            // print_Result(v);
            break;
        case AST_DEF:
            ASTDef_stmt(node);
            break;
        case AST_FUN_NAME:
            v = ASTFun_call(find_def(node->lhs, map), node->rhs);
            break;
        case AST_FUN_CALL:
            v = ASTFun_call(node->lhs, node->rhs);
            break;
        case AST_FUN_EXP:
            v = ASTFun_call(node, NULL);
            break;
        case AST_NULL:
            /* do nothing */
            break;
        default:
            printf("unexpected type%d\n", node->type);
            puts("syntax error");
            exit(0);
            break;
    }
    return v;
}

/* void print_Result(ASTVal *v) {
    if (v->type == AST_NUM) {
        printf("val: %d\n", v->num);
    } else if (v->type == AST_BOOL){
        printf(v->b ? "val: #t\n" : "val: #f\n");
    } else if (v->type == AST_ID) {
        printf("val: %s\n", v->id);
    }
} */

int main(int argc, char *argv[]) {
    yyparse();
    def = new Map();
    ASTVisit(root, def);
    return(0);
}

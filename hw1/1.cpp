#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef struct
{
    string value;
    string type;
} Token;

queue<Token> Scan(void);
void Match(const Token &, const string &);
void Program(queue<Token> &);
void Stmts(queue<Token> &);
void Stmt(queue<Token> &);
void Exp(queue<Token> &);
void Primary(queue<Token> &);
void Primary_Tail(queue<Token> &);
void Error();

bool has_error = false;
char codes[1000000];
int idx;
vector<Token> ans;

int main(void)
{
    Token ts;
    queue<Token> tokens;
    int i = 0;
    idx = 0;
    while (scanf("%c", &codes[i++]) != EOF)
        ;
    tokens = Scan();

    Program(tokens);

    if (!has_error)
        for (auto ts : ans)
            cout << ts.type << " " << ts.value << endl;
    return 0;
}

queue<Token> Scan(void)
{
    queue<Token> res;
    Token ts;
    while (codes[idx] != '\0')
    {
        if (codes[idx] <= ' ' || codes[idx] == '\n')
            idx++;
        else if (codes[idx] == '(')
        {
            ts.value = '(';
            ts.type = "LBR";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == ')')
        {
            ts.value = ')';
            ts.type = "RBR";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == '.')
        {
            ts.value = '.';
            ts.type = "Dot";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == ';')
        {
            ts.value = ';';
            ts.type = "SEMICOLON";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == '\"')
        {
            idx++;
            string s = "";
            while (codes[idx] != '\"' && codes[idx] != '\0')
            {
                s += codes[idx];
                idx++;
            }
            if (codes[idx] == '\"')
            {
                idx++;
                ts.value = "\" " + s + " \"";
                ts.type = "STRLIT";
            }
            else
            {
                Error();
            }
            res.push(ts);
        }
        else if (isalpha(codes[idx]) || codes[idx] == '_')
        {
            string s = "";
            s += codes[idx];
            idx++;
            while (isdigit(codes[idx]) || isalpha(codes[idx]) || codes[idx] == '_')
            {
                s += codes[idx];
                idx++;
            }
            ts.value = s;
            ts.type = "ID";
            res.push(ts);
        }
        else
        {
            Error();
        }
    }
    return res;
}

void Match(const Token &ts, const string &type_name)
{
    if (ts.type != type_name && !has_error)
        Error();
    else
        ans.push_back(ts);
}

void Program(queue<Token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID" || tokens.front().type == "SEMICOLON")
        Stmts(tokens);
    else
        Error();
}
void Stmts(queue<Token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID" || tokens.front().type == "SEMICOLON")
    {
        Stmt(tokens);
        Stmts(tokens);
    }
    else
        Error();
}
void Stmt(queue<Token> &tokens)
{
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID" || tokens.front().type == "SEMICOLON")
    {
        Exp(tokens);
        if (tokens.empty())
        {
            Error(); //avoid no ;
            return;
        }
        Match(tokens.front(), "SEMICOLON");
        tokens.pop();
    }
    else
        Error();
}
void Exp(queue<Token> &tokens)
{
    if (tokens.empty())
        return;
    else if (tokens.front().type == "STRLIT")
    {
        Match(tokens.front(), "STRLIT");
        tokens.pop();
    }
    else if (tokens.front().type == "ID")
    {
        Primary(tokens);
    }
}
void Primary(queue<Token> &tokens) // just id empty also wrong
{
    if (tokens.front().type == "ID")
    {
        Match(tokens.front(), "ID");
        tokens.pop();
        Primary_Tail(tokens);
    }
    else
        Error();
}
void Primary_Tail(queue<Token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "Dot")
    {
        Match(tokens.front(), "Dot");
        tokens.pop();
        if (tokens.empty())
        {
            Error();
            return;
        }
        Match(tokens.front(), "ID");
        tokens.pop();
        Primary_Tail(tokens);
    }
    else if (tokens.front().type == "LBR")
    {
        Match(tokens.front(), "LBR");
        tokens.pop();
        Exp(tokens);
        if (tokens.empty())
        {
            Error();
            return;
        }
        Match(tokens.front(), "RBR");
        tokens.pop();
        Primary_Tail(tokens);
    }
}
void Error()
{
    if (!has_error)
    {
        has_error = true;
        cout << "invalid input" << endl;
        exit(0);
    }
}

#include <cstdio>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
typedef struct
{
    string value;
    string type;
} Token;

queue<Token> Scan(void);
bool is_digit(char);
bool is_letter(char);
void Match(const Token &, const string &);
void Program(queue<Token> &);
void Stmts(queue<Token> &);
void Stmt(queue<Token> &);
void Exp(queue<Token> &);
void Primary(queue<Token> &);
void Primary_Tail(queue<Token> &);
void Error(const string &);

bool has_error = false;
char codes[1000000];
int codes_idx;
vector<Token> ans;

int main(void)
{
    Token ts;
    queue<Token> tokens;
    int i = 0;
    codes_idx = 0;
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
    while (codes[codes_idx] != '\0')
    {
        if (codes[codes_idx] <= ' ' || codes[codes_idx] == '\n')
            codes_idx++;
        else if (codes[codes_idx] == '(')
        {
            ts.value = '(';
            ts.type = "LBR";
            res.push(ts);
            codes_idx++;
        }
        else if (codes[codes_idx] == ')')
        {
            ts.value = ')';
            ts.type = "RBR";
            res.push(ts);
            codes_idx++;
        }
        else if (codes[codes_idx] == '.')
        {
            ts.value = '.';
            ts.type = "DOT";
            res.push(ts);
            codes_idx++;
        }
        else if (codes[codes_idx] == '\"')
        {
            codes_idx++;
            string s = "";
            while (codes[codes_idx] != '\"' && codes[codes_idx] != '\0')
            {
                s += codes[codes_idx];
                codes_idx++;
            }
            if (codes[codes_idx] == '\"')
            {
                codes_idx++;
                ts.value = "\"" + s + "\"";
                ts.type = "STRLIT";
            }
            else
            {
                ts.value = "\"" + s;
                ts.type = "err";
            }
            res.push(ts);
        }
        else if (is_letter(codes[codes_idx]) || codes[codes_idx] == '_')
        {
            string s = "";
            s += codes[codes_idx];
            codes_idx++;
            while (is_digit(codes[codes_idx]) || is_letter(codes[codes_idx]) || codes[codes_idx] == '_')
            {
                s += codes[codes_idx];
                codes_idx++;
            }
            ts.value = s;
            ts.type = "ID";
            res.push(ts);
        }
        else
        {
            ts.value = codes[codes_idx];
            ts.type = "err";
            res.push(ts);
            codes_idx++;
        }
    }
    return res;
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void Match(const Token &ts, const string &type_name)
{
    if (ts.type != type_name && !has_error)
        Error("Match");
    else
        ans.push_back(ts);
}

void Program(queue<Token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID")
        Stmts(tokens);
    else
        Error("Program");
}
void Stmts(queue<Token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID")
    {
        Stmt(tokens);
        Stmts(tokens);
    }
    else
    {
        Error("Stmts");
    }
}
void Stmt(queue<Token> &tokens)
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
    else if (tokens.front().type == "err")
        Error("Stmt");
}

void Primary(queue<Token> &tokens)
{
    if (tokens.front().type == "ID")
    {
        Match(tokens.front(), "ID");
        tokens.pop();
        Primary_Tail(tokens);
    }
    else
        Error("Primary");
}
void Primary_Tail(queue<Token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "DOT")
    {
        Match(tokens.front(), "DOT");
        tokens.pop();
        if (tokens.empty())
        {
            Error("EMPTY");
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
        Stmt(tokens);
        if (tokens.empty())
        {
            Error("EMPTY");
            return;
        }
        Match(tokens.front(), "RBR");
        tokens.pop();
        Primary_Tail(tokens);
    }
    else if (tokens.front().type == "err")
        Error("Primary_Tail");
}
void Error(const string &msg)
{
    if (!has_error)
    {
        has_error = true;
        cout << "invalid input" << endl;
        exit(EXIT_SUCCESS);
    }
}
// 1 program → stmts
// 2 stmts → stmt stmts
// 3 stmts → λ
// 4 stmt → primary
// 5 stmt →
// 6 stmt → λ
// 7 primary → ID primary_tail
// 8 primary_tail → DOT ID primary_tail
// 9 primary_tail → LBR stmt RBR primary_tail
// 10 primary_tai → λ
// int:
// none
// double:
// a:6.147483647

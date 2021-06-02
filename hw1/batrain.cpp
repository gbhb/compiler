#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct
{
    string type;
    string value;
} token;

queue<token> scan(void);
void program(queue<token> &);
void stmts(queue<token> &);
void stmt(queue<token> &);
void exp(queue<token> &);
void primary(queue<token> &);
void primary_tail(queue<token> &);
void match(const token &, const string &);
void error();

bool err = false;
char codes[1000000];
int idx;
vector<token> ans;

int main(void)
{
    queue<token> tokens;
    token ts;
    int i = 0;
    idx = 0;
    while (scanf("%c", &codes[i++]) != EOF)
        ;
    tokens = scan();
    program(tokens);
    if (!err)
        for (auto ts : ans)
            cout << ts.type << " " << ts.value << endl;
    return 0;
}

queue<token> scan(void)
{
    queue<token> res;
    token ts;
    while (codes[idx] != '\0')
    {
        if (codes[idx] <= ' ' || codes[idx] == '\n')
        {
            idx++;
        }
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
            ts.type = "DOT";
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
                ts.value = "\"" + s + "\"";
                ts.type = "STRLIT";
            }
            else
            {
                ts.value = "\"" + s; // ex: "sdfa
                ts.type = "err";
            }
            res.push(ts);
        }
        else if (isalpha(codes[idx]) || codes[idx] == '_')
        {
            string s = "";
            s += codes[idx];
            idx++;
            while (isalpha(codes[idx]) || isdigit(codes[idx]) || codes[idx] == '_')
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
            ts.value = codes[idx];
            ts.type = "err";
            res.push(ts);
            idx++;
        }
    }
    return res;
}
void match(const token &ts, const string &type_name)
{
    if (ts.type != type_name && !err)
        error();
    else
        ans.push_back(ts);
}
void program(queue<token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID" || tokens.front().type == "SEMICOLON")
        stmts(tokens);
    else
        error();
}
void stmts(queue<token> &tokens)
{
    if (tokens.empty())
        return;
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID" || tokens.front().type == "SEMICOLON")
    {
        stmt(tokens);
        stmts(tokens);
    }
    else
        error();
}
void stmt(queue<token> &tokens)
{
    if (tokens.front().type == "STRLIT" || tokens.front().type == "ID" || tokens.front().type == "SEMICOLON")
    {
        exp(tokens);
        if (tokens.empty())
        {
            error(); //ex: asdf
            return;
        }
        match(tokens.front(), "SEMICOLON");
        tokens.pop();
    }
    else
        error();
}
void exp(queue<token> &tokens)
{
    if (tokens.empty())
        return;
    else if (tokens.front().type == "STRLIT")
    {
        match(tokens.front(), "STRLIT");
        tokens.pop();
    }
    else if (tokens.front().type == "ID")
    {
        primary(tokens);
    }
    else if (tokens.front().type == "err")
        error();
}
void primary(queue<token> &tokens)
{
    if (tokens.front().type == "ID")
    {
        match(tokens.front(), "ID");
        tokens.pop();
        primary_tail(tokens);
    }
    else
        error();
}
void primary_tail(queue<token> &tokens)
{
    if (tokens.empty())
    {
        return;
    }
    if (tokens.front().type == "DOT")
    {
        match(tokens.front(), "DOT");
        tokens.pop();
        if (tokens.empty())
        {
            error(); // ex: dsfasdf.
            return;
        }
        match(tokens.front(), "ID");
        tokens.pop();
        primary_tail(tokens);
    }
    else if (tokens.front().type == "LBR")
    {
        match(tokens.front(), "LBR");
        tokens.pop();
        exp(tokens);
        if (tokens.empty())
        {
            error(); // ex: str(
            return;
        }
        match(tokens.front(), "RBR");
        tokens.pop();
        primary_tail(tokens);
    }
    else if (tokens.front().type == "err")
        error();
}
void error()
{
    if (!err)
    {
        err = true;
        cout << "invalid input" << endl;
        exit(0);
    }
}
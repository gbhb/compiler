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

    if (!has_error)
    {
        while (!tokens.empty())
        {

            cout << tokens.front().type << " " << tokens.front().value << endl;
            tokens.pop();
        }
    }
    return 0;
}

queue<Token> Scan(void)
{
    queue<Token> res;
    Token ts;
    while (codes[idx] != '\0')
    {
        if (codes[idx] == ' ' || codes[idx] == '\n' || codes[idx] == '\r')
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
        else if (codes[idx] == '=')
        {
            ts.value = '=';
            ts.type = "OP";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == '+')
        {
            ts.value = '+';
            ts.type = "OP";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == '-')
        {
            ts.value = '-';
            ts.type = "OP";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == '*')
        {
            ts.value = '*';
            ts.type = "OP";
            res.push(ts);
            idx++;
        }
        else if (codes[idx] == '/')
        {
            ts.value = '/';
            ts.type = "OP";
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
        else if (isdigit(codes[idx]))
        {
            string s = "";
            s += codes[idx];
            idx++;
            while (isdigit(codes[idx]))
            {
                s += codes[idx];
                idx++;
            }
            ts.value = s;
            ts.type = "NUM";
            res.push(ts);
        }
        else
        {
            Error();
        }
    }
    return res;
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

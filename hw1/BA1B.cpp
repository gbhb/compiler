#include <iostream>
#include <queue>
using namespace std;
typedef struct
{
    string value;
    string type;
} Token;

bool is_digit(char);
bool is_operation(char);
void Error(string);
queue<Token> ReadFormula(string);
int EvalFormula(queue<Token> &);
int Prog(queue<Token> &);
int Exps(queue<Token> &);
int Exp(queue<Token> &);

bool has_error = false;

int main(void)
{
    cout << "Welcome use our calculator!" << endl;
    string line;
    cout << "> ";
    while (getline(cin, line))
    {
        if (line.empty())
        {
            has_error = false;
            cout << "> ";
            continue;
        }

        auto tokens = ReadFormula(line);

        if (!has_error)
        {
            if (!tokens.empty())
            {
                auto result = EvalFormula(tokens);
                if (!tokens.empty())
                    Error("Illegal formula!");
                if (!has_error)
                    cout << result << endl;
            }
        }
        if (cin.eof())
            break;
        has_error = false;
        cout << "> ";
    }
    cout << "ByeBye~" << endl;
    return 0;
}

queue<Token> ReadFormula(string line)
{
    queue<Token> res;
    Token ts;
    string::size_type i = 0;
    while (i < line.size())
    {
        if (line[i] <= ' ')
        {
            i++;
            continue;
        }
        else if ((line[i] == '+' && is_digit(line[i + 1])) || (line[i] == '-' && is_digit(line[i + 1])) || is_digit(line[i]))
        {
            string s = "";

            s += line[i++];
            while (is_digit(line[i]))
                s += line[i++];
            if (!(is_operation(line[i]) || line[i] <= ' '))
            {
                while (i < line.size() && line[i] > ' ' && line[i] <= '~')
                    s += line[i++];
                Error("Unknown token " + s);
                continue;
            }
            ts.value = s;
            ts.type = "INT";
            res.push(ts);
            continue;
        }
        else if (is_operation(line[i]))
        {
            ts.value = line[i];
            ts.type = "OPERATOR";
            res.push(ts);
            i++;
            continue;
        }
        else if (line[i] == '\n')
        {
            ts.value = line[i];
            ts.type = "LINEENTER";
            res.push(ts);
            i++;
            continue;
        }
        else
        {
            string s = "";
            while (i < line.size() && line[i] > ' ')
                s += line[i++];
            Error("Unknown token " + s);
        }
    }
    return res;
}

int EvalFormula(queue<Token> &tokens)
{
    return Prog(tokens);
}

int Prog(queue<Token> &tokens)
{
    return Exps(tokens);
}

int Exps(queue<Token> &tokens)
{
    return Exp(tokens);
}

int Exp(queue<Token> &tokens)
{
    if (tokens.empty())
    {
        Error("Illegal formula!");
        return 99999;
    }
    if (tokens.front().type == "INT")
    {
        int num = stoi(tokens.front().value);
        tokens.pop();
        return num;
    }
    if (tokens.front().type == "OPERATOR")
    {
        if (tokens.front().value == "+")
        {
            tokens.pop();
            return Exp(tokens) + Exp(tokens);
        }
        if (tokens.front().value == "-")
        {
            tokens.pop();
            return Exp(tokens) - Exp(tokens);
        }
        if (tokens.front().value == "*")
        {
            tokens.pop();
            return Exp(tokens) * Exp(tokens);
        }

        // divisor case
        tokens.pop();
        int first = Exp(tokens);
        int second = Exp(tokens);
        if (second == 0)
        {
            Error("Divide by ZERO!");
            return 99999;
        }
        return first / second;
    }
    Error("Illegal formula!");
    return 99999;
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
bool is_operation(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void Error(string msg)
{
    if (!has_error)
        cout << "Error: " << msg << endl;
    has_error = true;
}
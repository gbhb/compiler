#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
map<string, int> intmap;
map<string, long double> doumap;
bool ef = false;
class token
{
public:
    long double douv = 0.0;
    string v;
    string type;
};

string sid(string str, int &idx)
{
    int st = idx;
    while (isalpha(str[idx + 1]) || isdigit(str[idx + 1]) || str[idx + 1] == '_')
    {
        idx++;
    }
    return str.substr(st, idx + 1 - st);
}

token sdigit(string str, int &idx)
{
    token t;
    int tmpi = idx;
    long double num = (long double)(str[idx] - '0');
    int ccc = 1;
    while (isdigit(str[idx + 1]))
    {
        idx++;
        ccc++;
        num = num * 10 + str[idx] - '0';
    }
    if (str[idx + 1] == '.')
    {
        idx++;
        ccc++;
        int cnt = 0;
        while (isdigit(str[idx + 1]))
        {
            idx++;
            cnt++;
            ccc++;
            long double tmp = str[idx] - '0';
            for (int j = 0; j < cnt; j++)
            {
                tmp = tmp / 10;
            }
            num = num + tmp;
        }
    }
    t.type = "douv";
    t.douv = stod(str.substr(tmpi, ccc));
    return t;
}

token scan(string str, int &idx)
{
    token t;
    while (str[idx] == ' ' || str[idx] == '\n' || str[idx] == '\r')
        idx++;
    if (idx == str.size())
    {
        t.type == "END";
        return t;
    }
    if (str[idx] == ';')
    {
        t.type = ";";
        return t;
    }
    if (str.substr(idx, 3) == "int")
    {
        t.type = "itype";
        idx += 2;
        if (str[idx + 1] != ' ')
            ef = true;
    }
    else if (str.substr(idx, 6) == "double")
    {
        t.type = "dtype";
        idx += 5;
        if (str[idx + 1] != ' ')
            ef = true;
    }
    else if (str[idx] == '_' || isalpha(str[idx]))
    {
        t.v = sid(str, idx);
        t.type = "name";
    }
    else if (isdigit(str[idx]))
    {
        t = sdigit(str, idx);
    }
    else
    {
        switch (str[idx])
        {
        case '+':
            t.type = "plus";
            t.v = "+";
            break;
        case '-':
            t.type = "minus";
            t.v = "-";
            break;
        case '=':
            t.type = "assign";
            t.v = "=";
            break;
        default:
            ef = true;
            break;
        }
    }
    return t;
}
void mat(string str, vector<token> ts, int &idx, string type)
{
    if (ts[idx].type == type)
    {
        idx++;
    }
    else
    {
        ef = true;
    }
    return;
}

long double equ(string str, vector<token> ts, int &idx)
{
    if (ts[idx].type == ";")
        return 0;
    if (ts[idx].type == "plus")
    {
        mat(str, ts, idx, "plus");
        if (ef)
            return 0;
        mat(str, ts, idx, "douv");
        if (ef)
            return 0;
        if (!ef)
        {
            long double aa = ts[idx - 1].douv;
            return aa + equ(str, ts, idx);
        }
        else
            return 0;
    }
    if (ts[idx].type == "minus")
    {
        mat(str, ts, idx, "minus");
        if (ef)
            return 0;
        mat(str, ts, idx, "douv");
        if (ef)
            return 0;
        if (!ef)
        {
            long double aa = -ts[idx - 1].douv;
            return aa + equ(str, ts, idx);
        }
        else
            return 0;
    }
    if (ts[idx].type == "douv")
    {
        mat(str, ts, idx, "douv");
        if (ef)
            return 0;
        if (!ef)
        {
            long double aa = ts[idx - 1].douv;
            return aa + equ(str, ts, idx);
        }
        else
            return 0;
    }
    else
    {
        ef = true;
        return 0;
    }
}

void dou_assign(string str, vector<token> ts, int &idx)
{

    mat(str, ts, idx, "name");
    if (ef)
        return;
    string name;
    if (!ef)
    {
        name = ts[idx - 1].v;
        if (intmap.count(name))
        {
            ef = true;
            return;
        }
    }
    if (ts[idx].type == "assign")
    {
        mat(str, ts, idx, "assign");
        if (ef)
            return;
        doumap[name] = equ(str, ts, idx);
    }
    else if (ts[idx].type == ";")
    {
        doumap[name] = 0;
    }
    else
    {
        ef = true;
    }

    return;
}

void int_assign(string str, vector<token> ts, int &idx)
{

    mat(str, ts, idx, "name");
    if (ef)
        return;
    string name;
    if (!ef)
    {
        name = ts[idx - 1].v;
        if (doumap.count(name))
        {
            ef = true;
            return;
        }
    }
    if (ts[idx].type == "assign")
    {
        mat(str, ts, idx, "assign");
        if (ef)
            return;
        long double tmpd = equ(str, ts, idx);
        if (tmpd != (int)tmpd)
        {
            ef = true;
            return;
        }
        intmap[name] = (int)tmpd;
    }
    else if (ts[idx].type == ";")
    {
        intmap[name] = 0;
    }
    else
    {
        ef = true;
    }
    return;
}
void stmt(string str, vector<token> ts, int &idx)
{

    if (ts[idx].type == ";")
    {
        mat(str, ts, idx, ";");
        return;
    }
    if (ts[idx].type == "dtype")
    {
        mat(str, ts, idx, "dtype");
        if (ef)
            return;
        if (ts[idx].type == ";")
        {
            mat(str, ts, idx, ";");
            return;
        }
        dou_assign(str, ts, idx);
        if (ef)
            return;
    }
    else if (ts[idx].type == "itype")
    {
        mat(str, ts, idx, "itype");
        if (ef)
            return;
        if (ts[idx].type == ";")
        {
            mat(str, ts, idx, ";");
            return;
        }
        int_assign(str, ts, idx);
        if (ef)
            return;
    }
    else if (ts[idx].type == "plus" || ts[idx].type == "minus" || ts[idx].type == "douv")
    {
        equ(str, ts, idx);
        if (ef)
            return;
    }
    else if (ts[idx].type == "name")
    {
        if (intmap.count(ts[idx].v))
        {
            if (ts[idx + 1].type == ";")
                mat(str, ts, idx, "name");
            else if (ts[idx + 1].type == "assign")
            {
                int_assign(str, ts, idx);
                if (ef)
                    return;
            }
            else
            {
                ef = true;
            }

            if (ef)
                return;
        }
        else if (doumap.count(ts[idx].v))
        {
            if (ts[idx + 1].type == ";")
                mat(str, ts, idx, "name");
            else if (ts[idx + 1].type == "assign")
            {
                dou_assign(str, ts, idx);
                if (ef)
                    return;
            }
            else
            {
                ef = true;
            }
            if (ef)
                return;
        }
        else
        {
            ef = true;
        }
    }
    else
    {
        ef = true;
    }

    mat(str, ts, idx, ";");
    if (ef)
        return;
    return;
}

void stmts(string str, vector<token> ts, int &idx)
{
    if (idx == ts.size())
        return;
    if (ef)
        return;
    stmt(str, ts, idx);
    if (ef)
        return;
    stmts(str, ts, idx);
    if (ef)
        return;
    return;
}

void parser(string str, vector<token> ts, int &idx)
{
    stmts(str, ts, idx);
    if (ef)
        return;
    return;
}

int main()
{
    cout.precision(15);
    string tmp, str = "";
    while (cin >> tmp && tmp != "$")
    {
        str = str + " " + tmp;
    }
    vector<token> tokens;
    for (int idx = 0; idx < str.size(); idx++)
    {
        token t = scan(str, idx);
        if (t.type == "END" || ef)
            break;
        else
            tokens.push_back(t);
    }
    int idx = 0;
    if (!ef)
        parser(str, tokens, idx);

    if (ef)
        cout << "invalid output" << endl;
    else
    {
        cout << "int:" << endl;
        for (auto x : intmap)
        {
            cout << x.first << ":" << x.second << endl;
        }
        if (intmap.empty())
            cout << "none" << endl;
        cout << "double:" << endl;
        for (auto x : doumap)
        {
            if (x.second == (int)x.second)
                cout << x.first << ":" << x.second << ".0" << endl;
            else
            {
                cout << x.first << ":" << x.second << endl;
            }
        }
        if (doumap.empty())
            cout << "none" << endl;
    }
}
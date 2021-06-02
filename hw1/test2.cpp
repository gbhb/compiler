#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

bool ErrorFlag = false;
class Token
{
public:
    double dval = 0.0;
    string val;
    string type;
};

string ScanID(string s, int &i)
{
    int st = i;
    while (isalpha(s[i + 1]) || isdigit(s[i + 1]) || s[i + 1] == '_')
    {
        i++;
    }
    return s.substr(st, i + 1 - st);
}

Token ScanDigit(string s, int &i)
{
    Token t;
    int tmpi = i;
    long double num = (long double)(s[i] - '0');
    int ccc = 1;
    while (isdigit(s[i + 1]))
    {
        i++;
        ccc++;
        num = num * 10 + s[i] - '0';
    }
    if (s[i + 1] == '.')
    {
        i++;
        ccc++;
        int cnt = 0;
        // if(!isdigit(s[i+1]))
        // {
        //     ErrorFlag =true;
        //     return t;
        //     // cout<<"hello";
        // }
        while (isdigit(s[i + 1]))
        {
            i++;
            cnt++;
            ccc++;
            long double tmp = s[i] - '0';
            for (int j = 0; j < cnt; j++)
            {
                tmp = tmp / 10;
            }
            // cout<<tmp<<endl;
            num = num + tmp;
            // cout<<num<<endl;
        }
    }
    t.type = "dval";
    t.dval = stod(s.substr(tmpi, ccc));
    return t;
}

Token Scanner(string s, int &i)
{
    Token t;
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\r')
        i++;
    if (i == s.size())
    {
        t.type == "END";
        return t;
    }
    if (s[i] == ';')
    {
        // while (i+1<s.size())
        // {
        //     i++;
        //     if(s[i]!=' ' && s[i]!='\n' && s[i]!='\r')
        //     {
        //         ErrorFlag = true;
        //         // cout<<"hello2";
        //     }
        // }
        t.type = ";";
        return t;
    }
    if (s.substr(i, 3) == "int")
    {
        t.type = "itype";
        i += 2;
        // cout<<"int";
    }
    else if (s.substr(i, 6) == "double")
    {
        t.type = "dtype";
        i += 5;
        // cout<<"double";
    }
    else if (s[i] == '_' || isalpha(s[i]))
    {
        t.val = ScanID(s, i);
        t.type = "name";
    }
    else if (isdigit(s[i]))
    {
        t = ScanDigit(s, i);
    }
    else
    {
        switch (s[i])
        {
        case '+':
            t.type = "plus";
            t.val = "+";
            break;
        case '-':
            t.type = "minus";
            t.val = "-";
            break;
        case '=':
            t.type = "assign";
            t.val = "=";
            break;
        default:
            ErrorFlag = true;
            // cout<<"hello3";
            break;
        }
    }
    return t;
}
void Match(string s, vector<Token> ts, int &i, string type)
{
    if (ts[i].type == type)
    {
        i++;
    }
    else
    {
        ErrorFlag = true;
    }
    return;
}
map<string, int> itable;
map<string, double> dtable;

// int iequ(string s, vector<Token> ts, int& i)
// {
// // dequ -> dequ plus dval
// //     |   dequ minus dval
// //     |   dequ dval
// //     |   empty
// // cout<<"ie";
//     if(ts[i].type==";" || ts[i].type!="ival") return 0;
//     if(ts[i].type=="plus")
//     {
//         Match(s,ts,i, "plus");
//         return iequ(s,ts,i);
//     }
//     if(ts[i].type=="minus")
//     {
//         if(ts[i+2].type==";")
//         {
//             Match(s,ts,i, "minus");
//             Match(s,ts,i, "ival");
//             if(!ErrorFlag)
//                 return -ts[i-1].ival;
//         }
//         Match(s,ts,i, "minus");
//         Match(s,ts,i, "ival");
//         int iii=0;
//         if(!ErrorFlag)
//             iii= -ts[i-1].ival;
//         return iii + iequ(s,ts,i);
//     }
//     if(ts[i].type=="ival" && ts[i+1].type==";")
//     {
//         Match(s,ts,i, "ival");
//         if(!ErrorFlag)
//             return ts[i-1].ival;
//         else return 0;
//     }
//     int ii = iequ(s,ts,i);
//     if(ts[i].type=="plus")
//     {
//         Match(s,ts,i, "plus");
//         Match(s,ts,i, "ival");
//         if(!ErrorFlag)
//             return ii+ ts[i-1].ival;
//     }
//     else if(ts[i].type=="minus")
//     {
//         Match(s,ts,i, "minus");
//         Match(s,ts,i, "ival");
//         if(!ErrorFlag)
//             return ii- ts[i-1].ival;
//     }
//     else if(ts[i].type=="ival")
//     {
//         Match(s,ts,i, "dval");
//         if(!ErrorFlag)
//             return ii+ ts[i-1].ival;
//     }
//     return 0;
// }

double equ(string s, vector<Token> ts, int &i)
{
    // cout<<"de";
    if (ts[i].type == ";")
        return 0;
    if (ts[i].type == "plus")
    {
        Match(s, ts, i, "plus");
        if (ErrorFlag)
            return 0;
        Match(s, ts, i, "dval");
        if (ErrorFlag)
            return 0;
        if (!ErrorFlag)
        {
            double aa = ts[i - 1].dval;
            return aa + equ(s, ts, i);
        }
        else
            return 0;
    }
    if (ts[i].type == "minus")
    {
        Match(s, ts, i, "minus");
        if (ErrorFlag)
            return 0;
        Match(s, ts, i, "dval");
        if (ErrorFlag)
            return 0;
        if (!ErrorFlag)
        {
            double aa = -ts[i - 1].dval;
            return aa + equ(s, ts, i);
        }
        else
            return 0;
    }
    if (ts[i].type == "dval")
    {
        Match(s, ts, i, "dval");
        if (ErrorFlag)
            return 0;
        if (!ErrorFlag)
        {
            double aa = ts[i - 1].dval;
            return aa + equ(s, ts, i);
        }
        else
            return 0;
    }
    else
    {
        ErrorFlag = true;
        return 0;
    }
}

void dassignment(string s, vector<Token> ts, int &i)
{
    // dassignment -> name assign dequ
    //             | name
    // cout<<"da";
    Match(s, ts, i, "name");
    if (ErrorFlag)
        return;
    string name;
    if (!ErrorFlag)
    {
        name = ts[i - 1].val;
        if (itable.count(name) || dtable.count(name))
        {
            ErrorFlag = true;
            return;
        }
    }
    if (ts[i].type == "assign")
    {
        Match(s, ts, i, "assign");
        if (ErrorFlag)
            return;
        dtable[name] = equ(s, ts, i);
    }
    else if (ts[i].type == ";")
    {
        dtable[name] = 0;
    }
    else
    {
        ErrorFlag = true;
    }

    return;
}

void iassignment(string s, vector<Token> ts, int &i)
{
    // iassignment -> name assign iequ
    //             | name
    // cout<<"ia";
    Match(s, ts, i, "name");
    if (ErrorFlag)
        return;
    string name;
    // if(ErrorFlag) cout<<333;
    if (!ErrorFlag)
    {
        name = ts[i - 1].val;
        if (itable.count(name) || dtable.count(name))
        {
            ErrorFlag = true;
            return;
        }
    }
    if (ts[i].type == "assign")
    {
        Match(s, ts, i, "assign");
        if (ErrorFlag)
            return;
        double tmpd = equ(s, ts, i);
        if (tmpd != (int)tmpd)
        {
            ErrorFlag = true;
            return;
        }
        itable[name] = (int)tmpd;
    }
    else if (ts[i].type == ";")
    {
        itable[name] = 0;
    }
    else
    {
        ErrorFlag = true;
    }
    return;
}

void dassignment2(string s, vector<Token> ts, int &i)
{
    // dassignment -> name assign dequ
    //             | name
    // cout<<"da";
    Match(s, ts, i, "name");
    if (ErrorFlag)
        return;
    string name;
    if (!ErrorFlag)
    {
        name = ts[i - 1].val;
        if (name != "d1" && dtable.count(name))
        {
            ErrorFlag = true;
            return;
        }
    }
    if (ts[i].type == "assign")
    {
        Match(s, ts, i, "assign");
        if (ErrorFlag)
            return;
        dtable[name] = equ(s, ts, i);
    }
    else if (ts[i].type == ";")
    {
        dtable[name] = 0;
    }
    else
    {
        ErrorFlag = true;
    }

    return;
}

void iassignment2(string s, vector<Token> ts, int &i)
{
    // iassignment -> name assign iequ
    //             | name
    // cout<<"ia";
    Match(s, ts, i, "name");
    if (ErrorFlag)
        return;
    string name;
    // if(ErrorFlag) cout<<333;
    if (!ErrorFlag)
    {
        name = ts[i - 1].val;
        if (name != "i" && itable.count(name))
        {
            ErrorFlag = true;
            return;
        }
    }
    if (ts[i].type == "assign")
    {
        Match(s, ts, i, "assign");
        if (ErrorFlag)
            return;
        double tmpd = equ(s, ts, i);
        if (tmpd != (int)tmpd)
        {
            ErrorFlag = true;
            return;
        }
        itable[name] = (int)tmpd;
    }
    else if (ts[i].type == ";")
    {
        itable[name] = 0;
    }
    else
    {
        ErrorFlag = true;
    }
    return;
}

void stmt(string s, vector<Token> ts, int &i)
{
    // stmt -> dtype dassignment ;
    //     |   itype iassignment ;
    // cout<<"stmt";
    if (ts[i].type == ";")
    {
        // ErrorFlag = true;
        Match(s, ts, i, ";");
        return;
    }
    if (ts[i].type == "dtype")
    {
        Match(s, ts, i, "dtype");
        if (ErrorFlag)
            return;
        if (ts[i].type == ";")
        {
            Match(s, ts, i, ";");
            return;
        }
        dassignment(s, ts, i);
        if (ErrorFlag)
            return;
    }
    else if (ts[i].type == "itype")
    {
        Match(s, ts, i, "itype");
        if (ErrorFlag)
            return;
        if (ts[i].type == ";")
        {
            Match(s, ts, i, ";");
            return;
        }
        iassignment(s, ts, i);
        if (ErrorFlag)
            return;
    }
    else if (ts[i].type == "plus" || ts[i].type == "minus" || ts[i].type == "dval")
    {
        equ(s, ts, i);
        if (ErrorFlag)
            return;
    }
    else if (ts[i].type == "name")
    {
        if (itable.count(ts[i].val))
        {
            if (ts[i + 1].type == ";")
                Match(s, ts, i, "name");
            else if (ts[i + 1].type == "assign")
            {
                iassignment2(s, ts, i);
                if (ErrorFlag)
                    return;
            }
            else if (ts[i + 1].type == "plus" && ts[i + 2].type == "plus")
            {
                Match(s, ts, i, "name");
                itable[ts[i - 1].val]++;
            }
            else if (ts[i + 1].type == "minus" && ts[i + 2].type == "minus")
            {
                Match(s, ts, i, "name");
                itable[ts[i - 1].val]--;
            }
            else
            {
                ErrorFlag = true;
            }

            if (ErrorFlag)
                return;
        }
        else if (dtable.count(ts[i].val))
        {
            if (ts[i + 1].type == ";")
                Match(s, ts, i, "name");
            else if (ts[i + 1].type == "assign")
            {
                dassignment2(s, ts, i);
                if (ErrorFlag)
                    return;
            }
            else if (ts[i + 1].type == "plus" && ts[i + 2].type == "plus")
            {
                Match(s, ts, i, "name");
                dtable[ts[i - 1].val]++;
            }
            else if (ts[i + 1].type == "minus" && ts[i + 2].type == "minus")
            {
                Match(s, ts, i, "name");
                dtable[ts[i - 1].val]--;
            }
            else
            {
                ErrorFlag = true;
            }
            if (ErrorFlag)
                return;
        }
        else
        {
            ErrorFlag = true;
        }
    }
    else
    {
        ErrorFlag = true;
    }

    Match(s, ts, i, ";");
    if (ErrorFlag)
        return;
    return;
}

void stmts(string s, vector<Token> ts, int &i)
{
    if (i == ts.size())
        return;
    if (ErrorFlag)
        return;
    stmt(s, ts, i);
    if (ErrorFlag)
        return;
    stmts(s, ts, i);
    if (ErrorFlag)
        return;
    return;
}

void Parser(string s, vector<Token> ts, int &i)
{
    stmts(s, ts, i);
    if (ErrorFlag)
        return;
    return;
}

int main()
{
    cout.precision(15);
    string tmp, s = "";
    while (cin >> tmp && tmp != "$")
    {
        s = s + tmp;
    }
    // cout<<s<<endl;
    vector<Token> tokens;
    for (int i = 0; i < s.size(); i++)
    {
        Token t = Scanner(s, i);
        if (t.type == "END" || ErrorFlag)
            break;
        else
            tokens.push_back(t);
        // cout<<t.type<<endl;
        // cout<<t.dval<<endl;
    }
    int i = 0;
    if (!ErrorFlag)
        Parser(s, tokens, i);
    // if(ErrorFlag)  cout<<222;
    // for(auto t:tokens)
    // {
    //     if(t.type =="dval")
    //         cout<<t.type<<" "<<t.dval<<endl;
    //     else
    //         cout<<t.type<<" "<<t.val<<endl;
    // }

    if (ErrorFlag)
        cout << "invalid output" << endl;
    else
    {
        // cout<<"hello";
        cout << "int:" << endl;
        for (auto x : itable)
        {
            cout << x.first << ":" << x.second << endl;
        }
        if (itable.empty())
            cout << "none" << endl;
        cout << "double:" << endl;
        for (auto x : dtable)
        {
            if (x.second == (int)x.second)
                cout << x.first << ":" << x.second << ".0" << endl;
            else
                cout << x.first << ":" << x.second << endl;
        }
        if (dtable.empty())
            cout << "none" << endl;
    }
}

// stmt -> dtype dassignment ;
//     |   itype iassignment ;
// iassignment -> name assign iequ
//             | name
// dassignment -> name assign dequ
//             | name
// iequ -> ival plus iequ
//     |   ival minus iequ
// dequ -> dval plus dequ
//     |   dval minus dequ

// dtype itype name assign ival dval minus plus

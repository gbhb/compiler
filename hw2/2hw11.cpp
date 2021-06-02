#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

unordered_map<char, vector<string>> rule;
unordered_map<char, set<char>> first;

void findfirst(char ch)
{
    for (int i = 0; i < rule[ch].size(); i++)
    {
        set<char> ruletmp;
        for (int j = 0; j < rule[ch][i].size(); j++)
        {
            char now = rule[ch][i][j]; //第I個vector裡的str的第j個字
            set<char> NowFirstTmp;
            //terminal
            if (isupper(now) || now == ';' || now == '$')
            {
                NowFirstTmp.insert(now);
                cout << "1 ";
                cout << now << ' ';
                cout << endl;
            }
            //nonterminal
            else
            {
                if (first.find(now) == first.end()) // nonterminal還沒有first過裡面沒東西
                    findfirst(now);
                NowFirstTmp.insert(first[now].begin(), first[now].end());
                cout << "2 ";
                for (auto it = NowFirstTmp.begin(); it != NowFirstTmp.end(); ++it)
                    cout << *it << ' ';
                cout << endl;
            }
            ruletmp.insert(NowFirstTmp.begin(), NowFirstTmp.end());
            cout << "3 ";
            for (auto it = ruletmp.begin(); it != ruletmp.end(); ++it)
                cout << *it << ' ';
            cout << endl;
            if (NowFirstTmp.find(';') == NowFirstTmp.end())
            {
                ruletmp.erase(';'); // a ;
                break;
            }
        }
        first[ch].insert(ruletmp.begin(), ruletmp.end());
        cout << endl;
    }
}

int main()
{
    char ch;
    string s;
    while (cin >> ch >> s)
    {
        if (s == "ND_OF_GRAMMAR")
            break;
        size_t pos;
        while (pos = s.find('|'), pos != string::npos) //npos可以表示string的結束位置，是string::type_size 型別的，也就是find（）返回的型別。find函式在找不到指定值得情況下會返回string::npos。舉例如下（計算字串中含有的不同字元的個數）
        {
            //cout << s.substr(0, pos) << endl;
            rule[ch].push_back(s.substr(0, pos));
            s.erase(0, pos + 1);
        }
        //cout << s << endl;
        rule[ch].push_back(s);
    }
    for (char ch = 'z'; ch >= 'a'; ch--)
    {
        if (rule.find(ch) == rule.end()) //沒東西 繼續
            continue;
        if (first.find(ch) == first.end()) //一開始一定空的
            findfirst(ch);
    }
    for (char ch = 'z'; ch >= 'a'; ch--)
    {
        if (first.find(ch) == first.end())
            continue;
        cout << ch << " ";
        for (auto it = first[ch].rbegin(); it != first[ch].rend(); it++)
            cout << *it;

        cout << endl;
    }
    cout << "END_OF_FIRST" << endl;
}
#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
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
            char now = rule[ch][i][j];
            set<char> NowFirstTmp;
            //terminal
            if (isupper(now) || now == ';' || now == '$')
            {
                NowFirstTmp.insert(now);
            }
            //nonterminal
            else
            {
                if (first.find(now) == first.end())
                    findfirst(now);
                NowFirstTmp.insert(first[now].begin(), first[now].end());
            }
            ruletmp.insert(NowFirstTmp.begin(), NowFirstTmp.end());
            if (NowFirstTmp.find(';') == NowFirstTmp.end())
            {
                ruletmp.erase(';');
                break;
            }
        }
        first[ch].insert(ruletmp.begin(), ruletmp.end());
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
        while (pos = s.find('|'), pos != string::npos)
        {
            rule[ch].push_back(s.substr(0, pos));
            s.erase(0, pos + 1);
        }
        rule[ch].push_back(s);
    }
    for (char ch = 'z'; ch >= 'a'; ch--)
    {
        if (rule.find(ch) == rule.end())
            continue;
        if (first.find(ch) == first.end())
            findfirst(ch);
    }
    for (char ch = 'z'; ch >= 'a'; ch--)
    {
        if (first.find(ch) == first.end())
            continue;
        cout << ch << " ";
        for (auto it = first[ch].rbegin(); it != first[ch].rend(); it++)
            cout << *it;

        cout << "\r\n";
    }
    cout << "END_OF_FIRST"
         << "\r\n";
}
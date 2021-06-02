#include <bits/stdc++.h>

using namespace std;

void test_input(vector<vector<string> > tmp_grammar_list)
{
    for(int i=25; i>=0; i--)
    {
        cout<< (char)(i+'a')<<" ";
        for(auto x:tmp_grammar_list[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

bool is_Terminal(char c)
{
    if(c>='a' && c<='z') return false;
    if((c>='A' && c<='Z') || c == '!' || c=='@' || c=='#' || c=='%' || c=='^' || c=='&' || c=='*' || c=='$') return true;
}
vector<bool> first_done(26,false);
vector<set<char> > first_set_list(26, set<char>());
vector<set<char> > follow_set_list(26, set<char>());
vector<vector<string> > grammar_list(26);

set<char> first(char nonTerminal)
{
    if(first_done[(int)(nonTerminal-'a')])
    {
        return first_set_list[(int)(nonTerminal-'a')];
    }
    set<char> first_set;
    for(auto s: grammar_list[(int)(nonTerminal-'a')])
    {
        if(s==";")
        {
            first_set.insert(';');
            continue;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(is_Terminal(s[i]))
            {
                first_set.insert(s[i]);
                break;
            }
            else
            {
                set<char> tmp= first(s[i]);
                first_done[(int)(s[i]-'a')] = true;
                for(auto c:tmp)
                {
                    if(c==';') continue;
                    first_set.insert(c);
                }
                if(!tmp.count(';'))
                    break;
                if(i==s.size()-1)
                    first_set.insert(';');
            }
        }
    }
    first_set_list[(int)(nonTerminal-'a')] = first_set; 
    return first_set;
}

void follow_step2(char nonTerminal)
{
    for(auto s: grammar_list[(int)(nonTerminal-'a')])
    {
        for(int i=0; i<s.size()-1; i++)
        {
            if(is_Terminal(s[i]))
                continue;
            if(is_Terminal(s[i+1]))
            {
                follow_set_list[(int)(s[i]-'a')].insert(s[i+1]);
            }
            else
            {
                for(int j=i+1; j<s.size(); j++)
                {
                    if(is_Terminal(s[j]))
                    {
                        follow_set_list[(int)(s[i]-'a')].insert(s[j]);
                        break;
                    }
                    else
                    {
                        set<char> tmp= first(s[j]);
                        for(auto c:tmp)
                        {
                            if(c==';') continue;
                            follow_set_list[(int)(s[i]-'a')].insert(c);
                        }                    
                        if(!tmp.count(';'))
                            break;
                    }
                }
            }
        }
    }
}

void follow_step3(char nonTerminal)
{
    for(auto s: grammar_list[(int)(nonTerminal-'a')])
    {
        int last_id = s.size()-1;
        if(is_Terminal(s[last_id]))
            continue;
        else
        {
            for(auto c:follow_set_list[(int)(nonTerminal-'a')])
            {
                if(c==';') continue;
                follow_set_list[(int)(s[last_id]-'a')].insert(c);
            }
        }
    }  
}

void follow_step4(char nonTerminal)
{
    for(auto s: grammar_list[(int)(nonTerminal-'a')])
    {
        set<char> first_res;
        for(int i=s.size()-1-1; i>=0; i--)
        {
            if(is_Terminal(s[i]) || is_Terminal(s[i+1]) || !first_set_list[(int)(s[i+1]-'a')].count(';'))
                break;
            else
            {
                set<char> tmp= first(s[i+1]);
                for(auto c:tmp)
                {
                    if(c==';') continue;
                    first_res.insert(c);
                }
                for(auto c:first_res)
                {
                    if(c==';') continue;
                    follow_set_list[(int)(s[i]-'a')].insert(c);
                }
                for(auto c:follow_set_list[(int)(nonTerminal-'a')])
                {
                    if(c==';') continue;
                    follow_set_list[(int)(s[i]-'a')].insert(c);
                }                
            }
        }
    }
}

int main()
{
    //input
    string grammar;
    bool go = true;
    while(getline(cin, grammar) && grammar.substr(0,14) != "END_OF_GRAMMAR")
    {
        int id= (int)(grammar[0]-'a'); 
        if(go)
        {
            follow_set_list[id].insert('$');
        }
        int start = 2; 
        for(int i=2; i<=grammar.size(); i++)
        {
            if(i == grammar.size() || grammar[i]=='|')
            {
                grammar_list[id].push_back(grammar.substr(start, i-start));
                start = i+1;
            }
        }
        go = false;
    }
    // test_input(grammar_list);

    //find first
    for(int i=0; i<26; i++)
    {
        if(grammar_list.empty() || first_done[i]) 
            continue;
        first_set_list[i] = first((char)('a'+i));
        first_done[i]=true;
    }
    //find follow step 2
    for(int i=0; i<26; i++)
    {
        if(grammar_list.empty()) 
            continue;
        follow_step2((char)('a'+i));
    }    
    //find follow step 3
    for(int k=0; k<26; k++)
    {
        for(int i=0; i<26; i++)
        {
            if(grammar_list.empty()) 
                continue;
            follow_step3((char)('a'+i));
        }        
    }
    //find follow step 4
    for(int k=0; k<26; k++)
    {
        for(int i=0; i<26; i++)
        {
            if(grammar_list.empty()) 
                continue;
            follow_step4((char)('a'+i));
        }        
    }
    //output
    for(int i=25; i>=0; i--)
    {
        if(follow_set_list[i].empty()) 
            continue;
        vector<char> tmp;
        for(auto c:follow_set_list[i])
        {
            tmp.push_back(c);
        }
        sort(tmp.begin(), tmp.end(),[](int a, int b){
            return a > b;
        });
        cout<<(char)('a'+i)<<" ";
        for(auto c:tmp)
            cout<<c;
        cout<<endl;
    }
    cout<<"END_OF_FOLLOW"<<endl;
}

/*
follow定義: follow(a)為緊接在 a 之後的所有可能terminal 或 $ 

網路上步驟：
1) FOLLOW(S) = { $ }   // where S is the starting Non-Terminal

2) If A -> pBq is a production, where p, B and q are any grammar symbols,
    then everything in FIRST(q)  except ; is in FOLLOW(B.

3) If A->pB is a production, then everything in FOLLOW(A) is in FOLLOW(B).

4) If A->pBq is a production and FIRST(q) contains ;, 
    then FOLLOW(B) contains { FIRST(q) – ; } U FOLLOW(A)
*/
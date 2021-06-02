#include<bits/stdc++.h>
using namespace std;

// STL declare
map<char, vector<string> > grammar;
map<char, set<char> > first;
set<char> AllChar;

string type(char c)	// classify c to nonterminal, terminal, semicolon, endofstring, and error(invalid input or exception).
{
	if(c>='a' && c<='z')
		return "nonterminal";
	else if(c==';')
		return "semicolon";
	else if(c=='$')
		return "terminal";
//		return "endofstring";
	else if(c>='A' && c<='Z')
		return "terminal";
	else
	{
		switch(c)
		{
			case '!':
			case '@':
			case '#':
			case '%':
			case '^':
			case '&':
			case '*':
				return "terminal";
			default:
				return "error";
		}
	}
	return "error";
}

void split(string s, char c, vector<string>* v)	//split s with char c, and put the result in v
{
	(*v).clear();
	int Begin = 0;
	for(int End = 0; End<s.size(); End++)
	{
		if(s[End] == c)
		{
			(*v).push_back(s.substr(Begin, End-Begin));
			Begin = End+1;
		}
	}
	(*v).push_back(s.substr(Begin, s.size()-Begin));
	return;
}

// subMain
void INITIALIZE();
void INPUT();
void PROCESS();
void OUTPUT();
	void FindFirst(char c);

int main()
{
	INITIALIZE();
	INPUT();
	PROCESS();
	OUTPUT();
    return 0;
}

void INITIALIZE()
{
	grammar.clear();
	first.clear();
	AllChar.clear();
}

void INPUT()
{
	string tmp1, tmp2;
	vector<string> v;
	while(cin>>tmp1)
	{
		if(tmp1=="END_OF_GRAMMAR")
			break;
		char c = tmp1[0];
		AllChar.insert(c);
		first[c]   = set<char>();
		grammar[c] = vector<string>();
		cin>>tmp2;
		split(tmp2, '|', &v);
		for(auto i:v)
			if(i!="")	grammar[c].push_back(i);
	}
	return;
}

void PROCESS()
{
	for(auto c:AllChar)
		FindFirst(c);
	return;
}

void OUTPUT()
{
	for(set<char>::reverse_iterator i = AllChar.rbegin(); i!=AllChar.rend(); i++)
	{
		cout<<*i<<" ";
		for(set<char>::reverse_iterator j = first[*i].rbegin(); j!=first[*i].rend(); j++)
			cout<<*j;
		cout<<"\r\n";
	}
	cout<<"END_OF_FIRST"<<"\r\n";

}

	void FindFirst(char c)
	{
		if(first[c].size()!=0)	//because no recusion
			return;
		for(string i:grammar[c])
		{
			for(int j_index=0; j_index<i.size(); j_index++)
			{
				char j = i[j_index];
				string T = type(j);
				if(T=="terminal")
				{
					first[c].insert(j);
					break;
				}
				else if(T=="nonterminal")
				{
					FindFirst(j);	//recursion
					
					for(char k:first[j])
						if(k!=';')
							first[c].insert(k);
	
					if( first[j].find(';') == first[j].end() )								// not found ;
						break;
					else if(first[j].find('$') == first[j].end() && j_index+1==i.size())	// found ; 
						first[c].insert(';');
				}
				else if(T=="semicolon")
					first[c].insert(';');
				
			}
		}
		return;
	}


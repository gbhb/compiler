#include<bits/stdc++.h>
using namespace std;

// STL declare
map<char, vector<string>, greater<char> > grammar;
map<char, set<char, greater<char> >, greater<char> > first;
map<char, set<char, greater<char> >, greater<char> > follow;
char firstGrammar;

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
void FIRST_PROCESS();
	void FindFirst(char c);
void FOLLOW_PROCESS();
	void AddFollow(char c, string s);
	void FindFollow(char c);
void FIRST_OUTPUT();
void FOLLOW_OUTPUT();

int main()
{
	while(true)
	{
	
	INITIALIZE();
	INPUT();
	
	FIRST_PROCESS();
	FOLLOW_PROCESS();
	
//	FIRST_OUTPUT();
	FOLLOW_OUTPUT();
	
	}
    return 0;
}

void INITIALIZE()
{
	grammar.clear();
	first.clear();
	follow.clear();
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
		cin>>tmp2;
		split(tmp2, '|', &v);
		
		grammar[c] = vector<string>();
		if(grammar.size()==1)
			firstGrammar = c;

		for(auto i:v)
			if(i!="")	grammar[c].push_back(i);
		first[c]   = set<char, greater<char> >();
		follow[c]   = set<char, greater<char> >();
		
	}
	return;
}

void FIRST_PROCESS()
{
	for(auto c:grammar)	// c is each of the pair<char, vector<string> > in grammar
		FindFirst(c.first);
	return;
}
	
	void FindFirst(char c)
	{
		if(first[c].size()!=0)	//because no recusion
			return;
		for(string i:grammar[c])
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
					
					for(char k:first[j])	//	first(c) += first(j);
						if(k!=';')	first[c].insert(k);
	
					if( first[j].find(';') == first[j].end() )								// not found ;
						break;
					else if(j_index+1==i.size())											// found ; 
						// if( first[j].find('$') == first[j].end() ) 							// if not found $
						first[c].insert(';');
				}
				else if(T=="semicolon")
					first[c].insert(';');
			}
		return;
	}


void FOLLOW_PROCESS()
{
	follow[firstGrammar].insert('$');
	
	for(auto c:grammar)	// c is each of the pair<char, string, vector<string> > in grammar
		for(auto s:c.second)	// there is a grammar "c.first -> s"
			for(int i=0; i<s.size(); i++)
				if( type(s[i])=="nonterminal" && i+1!=s.size())
					AddFollow(s[i], s.substr(i+1, s.size()-i-1) );
	// If A -> pBq is a production, where p, B and q are any grammar symbols, then everything in FIRST(q) except ';' is in FOLLOW(B).
	
	for(int i=0; i<2; i++)
	{
		for(auto c:grammar)	// c is each of the pair<char, vector<string> > in grammar
			FindFollow(c.first);
	}
	// If A->pB is a production, then everything in FOLLOW(A) is in FOLLOW(B).
	// If A->pBq is a production and FIRST(q) contains ';', then FOLLOW(B) contains { FIRST(q) – ; } U FOLLOW(A)
	
	
	
	return;
}

	void AddFollow(char c, string s)	// follow(c) must include first(s[0]), and if semicolon existing, continue the next index.
	{
		for(auto i:s)
		{
			if(type(i)=="terminal")
			{
				follow[c].insert(i);
				break;
			}
			else if(type(i)=="nonterminal")
			{
				for(auto j:first[i])
					if(j!=';')
						follow[c].insert(j);
						
				if(first[i].find(';')==first[i].end())
					break;
			}
		}
		return;
	}
	
	void FindFollow(char c)
	{
		for(auto s:grammar[c])
			for(int i=s.size()-1; i>=0; i--)
			{
				// follow( s[i] ) += follow(c)
				if(type(s[i])=="terminal")
					break;
				else if(type(s[i])=="nonterminal")
				{
					for(auto m:follow[c])
						if(m!=';')
							follow[ s[i] ].insert(m);
					if(first[ s[i] ].find(';')==first[ s[i] ].end())
						break;
				}
			}
		return;
	}
	
				
void FIRST_OUTPUT()
{
	for(auto i:first)
	{
		cout<<(i.first)<<" ";
		for(auto j:(i.second))
			cout<<j;
		cout<<"\r\n";
	}
	cout<<"END_OF_FIRST"<<"\r\n";
	return;
}

void FOLLOW_OUTPUT()
{
	for(auto i:follow)
	{
		cout<<(i.first)<<" ";
		for(auto j:(i.second))	//because giving operator, we just need normally traverse it.
			cout<<j;
		cout<<"\r\n";
	}
	cout<<"END_OF_FOLLOW"<<"\r\n";
	return;
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


例題： 
	假設符號與輸入輸出與 Domjudge3-1 First 定義相同，僅output最後字樣改變 
	sample input:  
	s AbdH
	b Cc
	c Bc|;
	d ef
	e G|;
	f F|;
	END_OF_GRAMMAR
	
	sample output:
	s $ 
	f H 
	e HF 
	d H
	c HFG
	b HFG
	END_OF_FOLLOW
 
看到的重點：
	第一行 grammar 的 LHS 有 $ 這個 follow (第一步是這個意思嗎？)
	分號不會出現 
	以此題來看有兩種情況： 
		對於  "s AbdH", 可看出 follow(b) 包含 First(d) 且若 First(d) 包含分號，則 follow(b) 包含 First(H) (這裡的遞迴類似 First 作法) 
		對於   "b Cc" , 可看出 follow(c) = follow(b)，也就是如果 c 出現在 b 的 RHS ，且其後皆可能為分號，就會成立 
		
		
順帶一提：
	First(s) = { A }
	First(f) = { F , ; } 
	First(e) = { G , ; }
	First(d) = { G , F , ; }
	First(c) = { B , ; }
	First(b) = { C }


*/ 

/*
更多testcase:

s acb|cBb|bA
a DA|bc
b G|;
c H|;
END_OF_GRAMMAR


s $
c HGB$
b HGA$
a HG$
END_OF_FOLLOW

c ea
a Aea|;
e db
b Bdb|;
d CcD|E
END_OF_GRAMMAR

e DA$
d DBA$
c D$  
b DA$
a D$ 
END_OF_FOLLOW
	
s aAaB|bBbA
a ;
a ;
END_OF_GRAMMAR

s $
a BA
b BA
END_OF_FOLLOW

s LiR|A
i sr
r Asr|;
END_OF_GRAMMAR

s RA$
r R
i R
END_OF_FOLLOW

s a
a Abd
d Dd|;
b B
c G
END_OF_GRAMMAR

s $
d $
c 
b D$
a $
END_OF_FOLLOW

s AbdH
b Cc
c Bc|;
d ef
e G|;
f F|;
END_OF_GRAMMAR

s $
f H
e HF
d H
c HGF
b HGF
END_OF_FOLLOW
*/

//include
#include<bits/stdc++.h>
using namespace std;

//define
#define m1 first
#define m2 second

//variable declare
vector< pair<char, vector<string> > > inputStream;
vector< pair<char, set<char> > > outputStream;
map<char, int> ind;
vector< string > First;

//basic function
bool isEOL(char c)
{
	if(c==';')				return true;
	else					return false;
}

bool isTerminal(char c)
{
	if(c>='A' && c<='Z')	return true;
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
			case '$':
			case '*':
				return true;
			default:
				break;
		}
	}
	return false;
}

bool isNonTerminal(char c)
{
	if(c>='a' && c<='z')	return true;
	else					return false;
}

bool isEOF(char c)
{
	if(c=='$')				return true;
	else					return false;
}


string TokenType(char c)
{
	if(isTerminal(c))		return "Terminal";
	if(isNonTerminal(c))	return "Nonterminal";
	if(isEOF(c))			return "EOF";
	if(isEOL(c))			return "EOL";
	return "Error";
}

//program function
void Initialize();
void Input();
void Process();
void ProcessInitialize();
void Split(string s);
void Output();
void reNew(char c, string s);

int main()
{
	Initialize();
	Input();
	Process();
	Output();
	return 0;
}


void Initialize()
{
	inputStream.clear();
	outputStream.clear();
	ind.clear();
}
 
void Input()
{
	string tmp1;
	string tmp2;
	while(cin>>tmp1)
	{
		if(tmp1=="END_OF_GRAMMAR")
			break;
		cin>>tmp2;
		inputStream.push_back(make_pair(tmp1[0], vector<string>() ));
		Split(tmp2);
		for(string data:First)
		{
			inputStream[inputStream.size()-1].m2.push_back(data);
		}
	}
	return;
}

void ProcessInitialize()	//sort and initialize outputStream
{
	int size = inputStream.size();
	sort(&inputStream[0], &inputStream[0]+size, greater< pair<char, vector<string> > >());
	for(int i=0; i<size; i++)
	{
		outputStream.push_back(make_pair(inputStream[i].m1, set<char>() ));
		ind[inputStream[i].m1] = i;
	}
	return;
}


void Process()
{
	ProcessInitialize();
	int size = inputStream.size();

	for(int T=0; T<=size; T++)
	{
		for(int i=0; i<size; i++)
		{
			for(string j:inputStream[i].m2)
			{
				// deal with ( inputStream[i].m1 -> j )
				reNew(inputStream[i].m1, j);
			}
			
		}																						
	}
}

void reNew(char c, string s)
{
	// (define First(a) = {a} if a is Terminal)
	if(isTerminal(s[0]))
	{
		outputStream[ind[c]].m2.insert(s[0]);
		return;
	}
	if(s==";")
	{
		outputStream[ind[c]].m2.insert(';');
		return;
	}
	set<char> ret = outputStream[ ind[s[0]] ].m2;	
	ret.erase(';');
	// initialize ret: ret = First(s[0])
	for(char i:s)
	{
		if(isNonTerminal(i))
		{
			for(char j:outputStream[ind[i]].m2)
			{
				if(isTerminal(j))
				{
					ret.insert(j);
				}
			}
			if(outputStream[ind[i]].m2.find(';')==outputStream[ind[i]].m2.end())
				break;
			else if(s[s.size()-1]==i)
			{
				ret.insert(';');
			}
		}
		else if(isTerminal(i))
		{
			ret.insert(i);
			break;
		}
	}
	for(char j:ret)
	{
		outputStream[ind[c]].m2.insert(j);
	}

	
	return;
}


void Split(string s)
{
	First.clear();
	int begin = 0;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='|')
		{
			First.push_back(s.substr(begin, i-begin));
			begin = i+1;
		}
	}
	First.push_back(s.substr(begin, s.size()-begin));
	return;
}


void Output()
{
	stack<char> tmp;
	for(int i=0; i<outputStream.size(); i++)
	{
		cout<<outputStream[i].m1<<" ";
		for(set<char>::iterator j = outputStream[i].m2.begin(); j!=(outputStream[i].m2.end()); j++)
		{
			tmp.push(*j);
		}
		while(!tmp.empty())
		{
			cout<<tmp.top();
			tmp.pop();
		}
		cout<<"\r\n";
	}
	cout<<"END_OF_FIRST"<<"\r\n";
}

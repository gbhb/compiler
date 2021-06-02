#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include <vector>
using namespace std;
string s, buf;
int a = 0, num;
bool digit = false;
int main()
{
  while (cin >> s)
  {
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == ' ')
      {
      }
      else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '=')
      {
        cout << "OP" << endl;
      }
      else if (s[i] == '(')
      {
        cout << "LBR" << endl;
      }
      else if (s[i] == ')')
      {
        cout << "RBR" << endl;
      }
      else if (isalpha(s[i]))
      {
        buf = buf + s[i];
        i++;
        while (isdigit(s[i]) || isalpha(s[i]))
        {
          cout << "ID " << buf << endl;
          buf = "";
        }
      }
      else if (isdigit(s[i]))
      {
        buf = buf + s[i];

        if (!isdigit(s[i + 1]))
        {
          cout << "NUM " << buf << endl;
          buf = "";
        }
      }
    }
  }
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

string conv(vector<string> v)
{
  string s, t;
  for(int i=0; i<v.size(); ++i){
    if(i)s += '\n';
    s += v[i];
  }
  s += '\0';
  int mark = 0;
  int size = 0;
  for(int i=0; i<s.size(); ++i){
    if(s[i] == '\0')continue;
    else if(!mark && s[i] == '\\' && s[i+1] == 'b'){ ++i; }
    else if(!mark && s[i] == '\\' && s[i+1] == 'i'){ ++i; }
    else if(!mark && s[i] == '\\' && s[i+1] == 's'){
      i += 2;        
      while( isdigit(s[i]) )++i;
      if(s[i] == '.'){
        ++i;
        while( isdigit(s[i]) )++i;          
      }
      --i;
    }
    else if(!mark && s[i] == '\\' && s[i+1] == '\\'){
      t += '\\';
      s[i+1] = '\0';
    }
    else if( s[i] == '\\' && s[i+1] == '*'){ ++i;  mark ^= 1; }
    else if(!mark && s[i] == '\\'){}
    else t += s[i];
  }
  
  return t;
}

int main(void)
{
  vector<string> v;
  for(string s; getline(cin, s); v.push_back(s));
  cout << conv(v) << endl;
  return 0;
}

//uva 271
#include <iostream>

using namespace std;

inline bool pz(char c)
{
  return 'p' <= c && c <= 'z';
}

bool parser(string s, int &p)
{
  if(pz(s[p]))return true;
  if(s[p] == 'C' || s[p] == 'D' || s[p] == 'E' || s[p] == 'I'){
    if(!parser(s, ++p))return false;
    return (p + 1 < s.size())? pz(s[++p]) : false;
  }
  else if(s[p] == 'N')
    return (p + 1 < s.size())? parser(s, ++p) : false;  
  return false;
}

int main(void)
{
  string s;
  while(cin >> s){
    int p = 0;
    cout << ((parser(s, p) && p+1 == s.size())? "YES" : "NO") << endl;
  }
  return 0;
}

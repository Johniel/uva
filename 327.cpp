#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

inline
bool isOp(char c)
{
  return c == '+' || c == '-';
}

int eval(string s, map<char, int> &m)
{
  int sum = 0;
  if(isOp(s[0])){
    int i;
    for(i=0; isOp(s[i]); ++i);
    while(isOp(s[0])){
      if(s[0] == '+')++m[s[i]];
      else --m[s[i]];
      s.erase(s.begin(), s.begin() + 2);
    }
  }
  int r = -1, l = 0;
  while(l + 1 < s.size()){
    for(++r;   r < s.size() && isOp(s[r]); ++r);
    for(l=r+1; l < s.size() && isOp(s[l]); ++l);        
    if(r >= s.size() || l >= s.size())break;
    if(isOp(s[r]) || isOp(s[l]))break;
    if(l - r > 5){
      if(s[l-1] == '+')++m[s[l]];
      else --m[s[l]];
      s.erase(s.begin() + --l);
      s.erase(s.begin() + --l);
    }
    else if(l - r > 2 && s[r+1] != s[r+2] && s[r+2] == s[r+3]){
      if(s[l-1] == '+')++m[s[l]];
      else --m[s[l]];
      s.erase(s.begin() + --l);
      s.erase(s.begin() + --l);
    }    
  }
  //cout << s << endl;
  sum += m[s[0]];
  for(int i=1; i<s.size(); ++i){
    if(isOp(s[i]))continue;
    if(s[i-1] == '+')sum += m[s[i]];
    else sum -= m[s[i]];
  }
  for(int i=0, j; i<s.size(); ++i){
    if(isOp(s[i]))continue;
    while(i < s.size() && isOp(s[i+1]) && s[i+1] == s[i+2]){
      if(s[i+1] == '+')++m[s[i]];
      else --m[s[i]];      
      i += 2;
    }
  }

  return sum;
}

int main(void)
{
  for(string s, t; getline(cin, s); ){
    t = s;
    map<char, int> m;
    for(int i=0; i<s.size(); ++i){
      if(s[i] == ' '){
	s.erase(s.begin() + i--);
      }
    }
    for(int i=0; i<s.size(); ++i){
      if(!isOp(s[i])){
	m[s[i]] = s[i] - 'a' + 1;
      }
    }
    int result = eval(s, m);
    cout << "Expression: " << t << endl;
    cout << "    value = " << result << endl;
    FOR(i, m){
      cout << "    " << i->first << " = " << i->second << endl;
    }
  }
  return 0;
}

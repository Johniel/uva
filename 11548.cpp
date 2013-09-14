#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

inline 
int solve(const string &s, const string &t)
{ 
  int result = 0;
  for(int i=0; i<t.size(); ++i){
    int cnt = 0;
    for(int j=0; j<s.size() && i+j<t.size(); ++j){
      if(s[j] == t[i + j])++cnt;
    }
    result = max(result, cnt);
  }
  return result;
}

int main(void)
{
  int tc, n;
  string s[70 + 1];
  for(cin >> tc; tc--; ){    
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> s[i];
    }   
    int result = 0;
    for(int i=0; i<n; ++i){
      for(int j=i+1; j<n; ++j){
	result = max(result, solve(s[i], s[j]));
	result = max(result, solve(s[j], s[i]));
      }
    }
    cout << result << endl;
  }
  return 0;
}

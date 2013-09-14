#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second

using namespace std;

string conv(string s)
{
  string t;
  for(int i=0; i<s.size(); ++i){
    t += tolower(s[i]);
  }
  return t;
}

#include <sstream>
int main(void)
{
  bool nl = false;
  int n;
  while(cin >> n){
    if(nl)cout << endl;
    else nl = true;
    map<string, int> m;
    while(true){
      string s, t;
      getline(cin, s);
      if(s == "EndOfText")break;
      if(s.size() == 0)continue;
      for(int j=0; j<s.size(); ++j){
	if(isalpha(s[j]))continue;
	s[j] = ' ';
      }
      istringstream iss(s);
      while(iss >> t){
	string u = conv(t);
	if(u.size())++m[u];
      }
    }
    bool flg = true;
    FOR(i, m){
      if(i->second != n)continue;
      flg = false;
      cout << i->first << endl;
    }
    if(flg)cout << "There is no such word." << endl;
  }
  return 0;
}

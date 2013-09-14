#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define LOOP(i, b, n) for(int i=0; i<(int)n; ++i)

using namespace std;

int main(void)
{
  for(int n, m; cin >> n >> m; ){
    map<string, string> M;
    string s, t;
    for(int i=0; i<n; ++i){
      cin >> s >> t;
      M.insert(make_pair(s, t));
    }
    for(int i=0; i<m; ++i){
      cin >> s;
      t = s;
      reverse(t.begin(), t.end());
      int p = (int)s.size() - 1;
      map<string, string>::iterator itr = M.find(s);
      if(itr != M.end()){
	cout << itr->second << endl;
      }
      else if(2 <= s.size() && t[0] == 'y' && !(t[1] == 'a' || 
						t[1] == 'i' || 
						t[1] == 'u' || 
						t[1] == 'e' || 
						t[1] == 'o')){
	cout << s.substr(0, p) << "ies" << endl;
      }
      else if(t[0] == 'o' || t[0] == 's' || t[0] == 'x'){
	cout << s << "es" << endl;
      }
      else if(2 <= t.size() && (t[0] == 'h') && (t[1] == 's' || t[1] == 'c')){
	cout << s << "es" << endl;
      }
      else {
	cout << s << 's' << endl;
      }
    }
  }
  return 0;
}

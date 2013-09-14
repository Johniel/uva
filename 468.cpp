#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
  return a.second < b.second;
}

int main(void)
{
  int tc;
  string s, t;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  while(tc--){
    getline(cin, s);
    getline(cin, t);

    pair<int, int> cnt1[CHAR_MAX], cnt2[CHAR_MAX];
    
    for(int i=0; i<CHAR_MAX; ++i){
      cnt1[i] = make_pair(i, 0);
      cnt2[i] = make_pair(i, 0);
    }

    for(int i=0; i<s.size(); ++i){
      if(isalpha(s[i])){
	++cnt1[s[i]].second;
      }
    }

    for(int i=0; i<t.size(); ++i){
      if(isalpha(t[i])){
	++cnt2[t[i]].second;
      }
    }

    map<char, char> m;
    sort(cnt1, cnt1 + CHAR_MAX, cmp);
    sort(cnt2, cnt2 + CHAR_MAX, cmp);
    
    for(int i=0; i<CHAR_MAX; ++i){
      m[cnt2[i].first] = cnt1[i].first;
    }
    
    for(int i=0; i<t.size(); ++i){
      if(isalpha(t[i])){
	cout << m[t[i]];
      }
      else cout << t[i];
    }
    cout << endl;
    if(tc)cout << endl;
    cin.ignore();
  }
  return 0;
}

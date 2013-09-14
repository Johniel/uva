#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int COLOR = 6;

inline
pair<int, int> check(const string &s, const string &t)
{
  pair<int, int> result = make_pair(0, 0);
  static int cnt1[CHAR_MAX];  
  static int cnt2[CHAR_MAX];
  fill(cnt1, cnt1 + CHAR_MAX, 0);
  fill(cnt2, cnt2 + CHAR_MAX, 0);
  for(int i=0; i<4; ++i){
    if(s[i] == t[i]){
      ++result.first;
    }
    else{
      ++cnt1[s[i]];
      ++cnt2[t[i]];
    }
  }
  for(int i=0; i<CHAR_MAX; ++i){
    if(cnt1[i] == 1 && cnt2[i] == 1){
      ++result.second;
    }
  }
  return result;
}

int main(void)
{
  const int ALL = 360;
  char c[COLOR] = {'R', 'G', 'B', 'Y', 'O', 'V'};
  char buff[5];
  int size = 0;
  string all[ALL];
  buff[4] = '\0';
  for(int i=0; i<COLOR; ++i){
    for(int j=0; j<COLOR; ++j){
      if(i == j)continue;
      for(int k=0; k<COLOR; ++k){
	if(i == k || j == k)continue;
	for(int l=0; l<COLOR; ++l){
	  if(i == l || j == l || k == l)continue;
	  buff[0] = c[i];
	  buff[1] = c[j];
	  buff[2] = c[k];
	  buff[3] = c[l];
	  all[size++] = string(buff);
	}
      }
    }
  }      

  int tc;
  for(cin >> tc; tc--; ){
    string s, t;
    pair<int, int> n, m;
    bool flg = false;
    cin >> s >> n.first >> n.second;
    cin >> t >> m.first >> m.second;
    for(int i=0; i<ALL && !flg; ++i){
      flg = (check(all[i], s) == n && check(all[i], t) == m);
    }
    cout << (flg ? "Possible" : "Cheat") << endl;
  }
  return 0;
}

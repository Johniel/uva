#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

const int N = 1 << 10;

int main(void)
{
  int word, tc, n;
  cin >> word;
  set<string> dic;
  while(word--){
    string s;
    cin >> s;
    if(s.size() <= 10){
      sort(s.begin(), s.end());
      dic.insert(s);
    }
  }
  pair<char, int> p[10 + 1];
  cin >> tc;
  while(tc--){
    cin >> n;        
    for(int i=0; i<n; ++i){
      cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    const int lim = 1 << n;
    int mx = 0;
    for(int i=1; i<lim; ++i){
      string t;
      int sum = 0;
      for(int j=0; j<n; ++j){
        if(i & (1 << j)){
          t += p[j].first;
          sum += p[j].second;
        }
      }
      if(dic.count(t)){
        mx = max(mx, sum);
      }
    }    
    cout << mx << endl;
  }
  return 0;
}

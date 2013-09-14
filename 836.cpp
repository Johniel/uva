#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 25 + 1;
  int g[N][N];
  int tc;
  cin >> tc;
  while(tc--){
    string s;
    cin >> s;
    for(int j=0; j<s.size(); ++j){
      g[0][j] = s[j] - '0';
    }
    for(int i=1; i<s.size(); ++i){
      cin >> s;
      for(int j=0; j<s.size(); ++j){
        g[i][j] = s[j] - '0';
      }
    }
    const int size = s.size();
    for(int i=0; i<size; ++i){
      int sum = 0;
      for(int j=0; j<size; ++j){
        if(g[i][j])++sum;
        else sum = 0;
        g[i][j] = sum;
      }
    }
    const int inf = 1 << 22;
    int mx = 0;
    for(int j=0; j<size; ++j){
      for(int i=0; i<size; ++i){
        int mn = inf;
        for(int k=i; k<size; ++k){
          if(g[i][j] == 0)break;
          mn = min(mn, g[k][j]);
          mx = max(mx, mn * (k - i + 1));
        }
      }
    }
    cout << mx << endl;
    if(tc)cout << endl;
    continue;
    for(int i=0; i<size; ++i){
      for(int j=0; j<size; ++j)cout << g[i][j]; cout << endl;
    }
  }
  return 0;
}

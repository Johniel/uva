#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    cin >> n >> m;    
    int a[m];
    for(int i=0; i<m; ++i){
      int sum = 0;
      for(int j=0; j<n; ++j){
        char c;
        cin >> c;
        if(c == '1')sum |= 1 << j;
      }
      a[i] = sum;
    }
    int mn = 1 << 22;
    for(int i=0; i<(1 << n); ++i){
      set<int> vis;
      int cnt = 0;
      int bit = 0;
      for(int j=0; j<n; ++j){
        if(i & (1 << j)){
          ++cnt;
          bit |= 1 << j;
        }
      }
      for(int j=0; j<m; ++j){
        vis.insert( a[j] & bit );
      }
      if( vis.size() == m )mn = min(mn, cnt);
    }
    cout << mn << endl;
  }
  return 0;
}

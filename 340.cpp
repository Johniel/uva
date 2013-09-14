#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
  int n;
  int tc = 0, cnt = 0;
  while(cin >> n && n){
    int a[n], b[n];
    bool vis[n];
    for(int i=0; i<n; ++i){
      cin >> a[i];
    }
    cout << "Game " << ++cnt << ":" << endl;
    while(true){
      for(int i=0; i<n; ++i){
        cin >> b[i];
      }
      fill(vis, vis + n, false);
      if(accumulate(b, b + n, 0) == 0)break;
      int s = 0, t = 0;
      for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
          if(vis[j])continue;
          if(a[i] != b[j])continue;
          if(i == j){
            vis[j] = true;
            ++s;
            break;
          }
          else if(a[i] != b[i] && a[j] != b[j]){
            vis[j] = true;
            ++t;
            break;
          }
        }        
      }
      cout << "    " << "(" << s << "," << t << ")" << endl;
    }
  }
  return 0;
}

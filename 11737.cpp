#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
  int n, tc = 0;
  while(cin >> n){
    pair<int, int> p[n];
    for(int i=0; i<n; ++i){
      cin >> p[i].first >> p[i].second;
    }
    int mn = 1 << 22;
    for(int i=0; i<n; ++i){
      if(p[i].first == p[i].second)mn = 0;
      for(int j=0; j<n; ++j){
        int tmp = abs(p[i].first - p[j].second);
        mn = min(mn, max((tmp+1)/2, 1));
      }
    }
    cout << "Case " << ++tc << " : " << mn << endl;
  }
  return 0;
}

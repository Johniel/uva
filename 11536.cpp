#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int N = 1000001;
  int x[N];
  lli contain[200];
  int tc;
  scanf("%d", &tc);
  while(tc--){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;
    for(int i=4; i<=n; ++i){
      x[i] = (x[i-1] + x[i-2] + x[i-3]) % m + 1;
    }

    //for(int i=1; i<=n; ++i)cout << x[i] << ' '; cout << endl;

    int sum = 0, elem = 0;
    int h = 1, t = 1;
    int mn = INT_MAX;
    fill(contain, contain + 200, 0);
    while(t <= n){
      for(; h <= n && elem != k; ++h){
        if(x[h] <= k){
          ++contain[x[h]];
          if(contain[x[h]] == 1)++elem;
        }
      }      
      if(elem != k)break;
      for(; t < h; ++t){
        if(x[t] <= k){
          if(contain[x[t]] == 1)break;
          --contain[x[t]];
        }
      }
      if(t == h)break;
      mn = min(mn, h - t);
      --contain[x[t]];
      --elem;
      ++t;
    }

    static int cnt = 0;
    if(mn == INT_MAX)printf("Case %d: sequence nai\n", ++cnt);
    else printf("Case %d: %d\n", ++cnt, mn);
  }
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int V = 26 + 1, L = 30 + 1;
  lli t[L][V];
  int edge;
  int g[V][V];
  bool dst[V];
  while(cin >> edge){
    fill(&g[0][0], &g[V-1][V], 0);
    fill(dst, dst + V, false);
    while(edge--){
      char a, b, c, d;
      cin >> a >> b >> c >> d;
      ++g[a - 'A'][b - 'A'];
      ++g[a - 'A'][c - 'A'];
      if(d == 'x')dst[a - 'A'] = true;
    }
    int len;
    cin >> len;
    fill(&t[0][0], &t[L-1][V], 0L);
    t[0][0] = 1L;
    for(int i=0; i<len; ++i){
      for(int j=0; j<V; ++j){
        if(t[i][j] == 0)continue;
        for(int k=0; k<V; ++k){
          if(g[j][k])t[i+1][k] += t[i][j] * g[j][k];
        }
      }
    }
    lli sum = 0;
    for(int i=0; i<V; ++i){
      if(dst[i])sum += t[len][i];
    }
    cout << sum << endl;
  }
  return 0;
}

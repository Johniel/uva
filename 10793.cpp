#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
  const int V = 100 + 1;
  const int inf = 1 << 28;
  int g[V][V];
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    int node, edge;
    fill(&g[0][0], &g[V-1][V], inf);
    cin >> node >> edge;
    for(int i=0; i<node; ++i){
      g[i][i] = 0;
    }
    for(int i=0; i<edge; ++i){
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a][b] = g[b][a] = min(g[a][b], c);
    }
    for(int k=0; k<node; ++k){      
      for(int i=0; i<node; ++i){
        for(int j=0; j<node; ++j){
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    vector<int> v;
    for(int i=5; i<node; ++i){
      bool flg = true;
      for(int j=0; j<node; ++j){
        flg = flg && g[i][j] < inf;
      }
      if(!flg)continue;
      if(g[i][0] == inf)continue;
      if(g[i][0] != g[i][1])continue;
      if(g[i][0] != g[i][2])continue;
      if(g[i][0] != g[i][3])continue;
      if(g[i][0] != g[i][4])continue;
      v.push_back(i);
    }
    int r = inf;
    for(int i=0; i<v.size(); ++i){
      int tmp = 0;
      for(int j=0; j<node; ++j){
        tmp = max( tmp, g[ v[i] ][ j ] );
      }
      r = min(r, tmp);
    }
    if(r == inf)r = -1;
    cout << "Map " << ++cnt << ": " << r << endl;
  }
  return 0;
}

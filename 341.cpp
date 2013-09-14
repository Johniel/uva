#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int inf = 1 << 22;
const int V = 100;
int g[V][V];
int path[V], w[V];
int vis[V];

int main(void)
{
  int node;
  while(cin >> node && node){
    fill(&g[0][0], &g[V-1][V], inf);
    for(int i=0; i<node; ++i){
      int e, a, b;
      cin >> e;
      while(e--){
        cin >> a >> b;
        g[i][a-1] = min(g[i][a-1], b);
      }
      w[i] = inf;
      vis[i] = false;
    }
    int a, b;    
    cin >> a >> b;
    --a;
    --b;
    w[a] = 0;
    path[a] = a;
    while(true){
      int mn = inf, idx;
      for(int i=0; i<node; ++i){
        if(!vis[i] && mn > w[i]){
          mn = w[i];
          idx = i;
        }
      }      
      if(mn == inf)break;
      vis[idx] = true;
      for(int i=0; i<node; ++i){
        if(!vis[i] && w[i] > w[idx] + g[idx][i]){
          w[i] = w[idx] + g[idx][i];
          path[i] = idx;
        }
      }
    }
    vector<int> v;
    for(int i=b; i!=path[i]; i=path[i]){
      v.push_back(i);
    }
    v.push_back(a);
    reverse(v.begin(), v.end());
    static int cnt = 0;
    cout << "Case " << ++cnt << ": Path =" << flush;
    for(int i=0; i<v.size(); ++i){
      cout << ' ' << v[i]+1;
    }
    cout << "; " << w[b] << " second delay" << endl;
  }
  return 0;
}

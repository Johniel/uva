#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int V = 100 + 1;

bool g[V][V];

int main(void)
{
  int n;
  while(cin >> n && n){
    fill(&g[0][0], &g[V-1][V], false);
    for(int src; cin >> src && src; ){
      for(int dst; cin >> dst && dst; ){
        g[src-1][dst-1] = true;
      }
    }
    for(int k=0; k<V; ++k){
      for(int i=0; i<V; ++i){
        for(int j=0; j<V; ++j){
          g[i][j] |= g[i][k] && g[k][j];
        }
      }
    }
    int q;
    cin >> q;
    while(q--){
      int src, dst;
      vector<int> v;
      cin >> src;
      --src;
      for(int i=0; i<n; ++i){
        if(!g[src][i]){
          v.push_back(i);
        }
      }
      cout << v.size() ;
      for(int i=0; i<v.size(); ++i){
        cout << ' ' << v[i] + 1;
      }
      cout << endl;
    }
  }
  return 0;
}

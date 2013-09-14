#include <iostream>
#include <algorithm>

using namespace std;

const int NODE = 30;
const int inf = 1 << 22;

int g[NODE][NODE];
int deg[NODE];

int sssp(void)
{
  int src = -1, dst = -1;
  for(int i=0; i<NODE; ++i){
    if(deg[i] % 2 == 0)continue;
    src = i;
    for(++i; i<NODE; ++i){
      if(deg[i] % 2 == 0)continue;
      dst = i;
      i = inf;
    }
  }
  if(src == -1 || dst == -1)return 0;
  for(int k=0; k<NODE; ++k){
    for(int i=0; i<NODE; ++i){
      for(int j=0; j<NODE; ++j){
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  return g[src][dst];
}

int main(void)
{
  while(true){
    string s;
    int sum = 0;
    fill(&g[0][0], &g[NODE-1][NODE], inf);
    fill(deg, deg + NODE, 0);
    while(cin >> s && s != "deadend"){
      int u = s[0] - 'a', v = s[(int)s.size() - 1] - 'a';
      sum += s.size();
      g[u][v] = g[v][u] = min(g[u][v], (int)s.size());
      ++deg[u];
      ++deg[v];
    }
    if(cin.eof())break;
    cout << sum + sssp() << endl;     
  }
  return 0;
}

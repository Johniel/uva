#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int NODE = 3000 + 1;
bool g[NODE][NODE];

int main(void)
{
  int tc, node, edge, src, dst, cnt, i, j, k;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d%d", &node, &edge);
    fill(&g[0][0], &g[node-1][node], false);
    while(edge--){
      scanf("%d%d", &src, &dst);
      --src;
      --dst;
      g[src][dst] = g[dst][src] = true;
    }
    cnt = 0;
    for(i=0; i<node; ++i){
      for(j=i+1; j<node; ++j){
        if(!g[i][j])continue;
        for(k=j+1; k<node; ++k){
          if(g[i][k] && g[j][k])++cnt;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}

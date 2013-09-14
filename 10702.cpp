#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int adj[101][101], T[101][1001], i, j, s, l, d;
  for(int node, src, dst, length, d; ; ){
    scanf("%d %d %d %d", &node, &src, &dst, &length);
    if(!(node | src | dst | length))break;
    for(i=0; i<node; ++i){
      for(j=0; j<node; ++j){
	scanf("%d", &adj[i][j]);
      }
    }
    fill(&T[0][0], &T[node-1][length+1], -(1 << 20));    
    T[src-1][0] = 0;
    for(l=1; l<=length; ++l){
      for(s=0; s<node; ++s){
	for(d=0; d<node; ++d){
	  if(T[d][l] < T[s][l-1] + adj[s][d])
	    T[d][l] = T[s][l-1] + adj[s][d];
	}
      }
    }
    int r = -1;
    for(i=0; i<dst; ++i){
      scanf("%d", &d);
      if(r < T[d-1][length])
	r = T[d-1][length];
    }
    printf("%d\n", r);
  }
  return 0;
}

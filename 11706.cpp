//uva 11706
#include <iostream>
#include <algorithm>

using namespace std;

const int NODE = 100 + 1, EMPTY = 0, W = 1, B = 2;

bool adj[NODE][NODE];
int color[NODE][NODE];

inline 
int rev(int c)
{
  return c == W? B : W;
}

bool rec(int src, int dst, int size, int c)
{
  
  color[src][dst] = color[dst][src] = c;
  for(int next=0; next<size; ++next){
    if(next == src || next == dst)continue;    
    if(adj[src][dst] + adj[dst][next] + adj[next][src] == 3){
      if(color[dst][next] == rev(c))return false;
      if(color[dst][next] == EMPTY && !rec(dst, next, size, c)){
	return false;
      }	
    }
    if(adj[src][dst] + adj[dst][next] + adj[next][src] == 2){
      int tmp = adj[dst][next]? dst : src;
      if(color[tmp][next] == c)return false;
      if(color[tmp][next] == EMPTY && !rec(tmp, next, size, rev(c))){
	return false;
      }
    }
  }
  return true;
}

bool coloring(int size)
{
  fill(&color[0][0], &color[size-1][size], EMPTY);
  for(int i=0; i<size; ++i){
    for(int j=i+1; j<size; ++j){
      if(adj[i][j] && color[i][j] == EMPTY && !rec(i, j, size, W)){
	return false;
      }
    }
  }
  return true;
}

int main(void)
{
  for(int node, edge; cin >> node >> edge; ){
    if(node + edge == 0)break;
    fill(&adj[0][0], &adj[node-1][node], false);
    int src, dst, cnt = 0;
    for(int i=0; i<edge; ++i){
      cin >> src >> dst;
      adj[src][dst] = adj[dst][src] = true;
    }
    cout << (coloring(node)? "YES" : "NO") << endl;
  }
  return 0;
}

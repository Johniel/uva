#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 100 + 1;

struct E{
  int src, dst;
  double cost, temp;
  E(){}
  E(int s, int d, double t, double c) 
    : src(s), dst(d), temp(t), cost(c) {}
};
typedef vector< vector<E> > Graph;

struct S{
  int node, prev;
  double cost;
  S(){}
  S(int n, int p, double c) 
    : node(n), prev(p), cost(c) {}
};
bool operator < (const S &a, const S &b)
{
  if( a.cost != b.cost )return a.cost > b.cost;
  if( a.node != b.node )return a.node > b.node;
  return a.prev > b.prev;
}

double sssp(const Graph &g, int src, int dst, const double lim, int path[])
{
  fill( path, path + N, -1 );

  static bool vis[N];
  fill( vis, vis + N, false );

  static double cost[N];  

  cost[dst] = -1;
  cost[src] = 0;

  priority_queue<S> q;
  for(q.push( S(src, -1, 0) ); q.size() && !vis[dst]; ){
    S n = q.top();
    q.pop();
    if( vis[n.node] )continue;
    vis[n.node] = true;
    cost[n.node] = n.cost;
    path[n.node] = n.prev;
    for(int i=0; i<g[n.node].size(); ++i){
      E e = g[n.node][i];
      if( vis[e.dst] )continue;
      if( lim < e.temp )continue;
      q.push( S(e.dst, e.src, cost[e.src] + e.cost) );
    }
  }

  /*
  for(int i=0; i<g.size(); ++i)cout << i << ' ' << cost[i] << endl;
  cout << "src : " << src << endl;
  cout << "dst : " << dst << endl;
  cout << "ret : " << cost[dst] << endl;
  cout << "lim : " << lim << endl;
  */

  return cost[dst];
}

void rec(int path[], int node)
{
  if( path[node] == -1 )printf("%d", node+1);
  else{
    rec( path, path[node] );
    printf(" %d", node+1);
  }
  return ;
}

int main(void)
{
  int node, edge;
  while( cin >> node >> edge ){
    int start, goal;
    double t[ edge ];
    Graph g( node );
    
    cin >> start >> goal;
    --start;
    --goal;

    for(int i=0; i<edge; ++i){
      int src, dst;
      double cost, temp;
      cin >> src >> dst >> temp >> cost;
      --src;
      --dst;
      t[i] = temp;
      g[src].push_back( E(src, dst, temp, cost) );
      g[dst].push_back( E(dst, src, temp, cost) );      
    }
    
    sort( t, t + edge );

    int s = 0, b = edge-1;
    double succ = -1;
    static int path[N];
    while( s + 1 < b ){
      int tmp_s = s;
      int tmp_b = b;
      
      int c = (s + b) / 2;
      double r = sssp( g, start, goal, t[c], path );      
      if( r < 0.0 )s = c;
      else b = c;
      if( tmp_s + 1 <  tmp_b ); else break;
    }

    succ = sssp( g, start, goal, t[b], path );

    rec( path, goal ); puts("");
    printf("%.1lf %.1lf\n", succ, t[b]);
    //puts("===========================================================");
  }
  return 0;
}

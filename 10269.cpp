#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

struct Edge{
  int dst, cost;
  Edge(int d, int c) : dst(d), cost(c) {}
};

struct Info{
  int dst, cost, cnt;
  bool run;
  Info(int d, int co, int cn, bool r) : 
    dst(d), cost(co), cnt(cn), run(r) {}
};

bool operator < (const Info &a, const Info &b){
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.cnt != b.cnt)return a.cnt > b.cnt;
  return a.dst > b.dst;
}

static const int MAX_V = 50 + 1;
static const int MAX_C = 50 + 1;
static const int MAX_SIZE = MAX_V + MAX_C;
static const int MAX_T = 10 + 1;
static const int INF = 1 << 20;

int G[MAX_T][MAX_SIZE][MAX_SIZE];
bool castle[MAX_SIZE];

void goNext(priority_queue<Info> &Q, Info next, int klim, int *dist[MAX_T])
{
  if(!castle[dst] && next.cnt > 0 && G[next.dst][j][next.cnt-1] + dist[j][next.cnt-1] < klim  &&
     dist[j][next.cnt-1] > G[next.dst][j][next.cnt-1] + dist[j][next.cnt-1]){//run
    if(next.run){
      
    }
    else{
      
    }
  }
  else if(dist[j][next.cnt] > G[next.dst][j][next.cnt] + dist[j][next.cnt]){//wark
    dist[j][next.cnt] = G[next.dst][j][next.cnt] + dist[j][next.cnt];
    Q.push(Info(j, dist[j], next.cnt, false));
  }
  return ;
}

int Dijkstra(const int &s, const int &t, const int &tlim, const int &klim, const int &size)
{
  priority_queue<Info> Q;
  bool visited[size][MAX_T];
  int dist[size][MAX_T];
  fill(&dist[0][0], &dist[size-1][MAX_T], INF);
  fill(&visited[0][0], &visited[size-1][MAX_T], false);
  for(Q.push(Info(0, 0, tlim, false)), dist[s] = 0; !Q.empty();){
    Info next = Q.front(); Q.pop();
    if(visited[next.dst][next.cnt])continue;
    visited[next.dst][next.cnt] = true;
    REP(j, size){
      if(G[next.dst][j][next.cnt] < INF)continue;
      goNext(Q, next, j, klim, dist);
  }
  return INF; 
}

int main(void)
{
  int tc, vil, csl, route, dlim, tlim;
  cin >> tc;
  while(tc--){
    cin >> vil >> csl >> route >> dlim >> tlim;
    fill(&G[0][0][0], &G[MAX_T-1][MAX_SIZE-1][MAX_SIZE], INF);
    fill(castle, castle + MAX_SIZE, false);
    REP(i, route){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      --src, --dst;
      REP(j, tlim+1)G[j][src][dst] = G[j][dst][src] = cost;
    }
    fill(castle + vil, castle + vil + csl, true);
    cout << Dijkstra(0, vil+csl-1, tlim, dlim, vil+csl) << endl;
  }
  return 0;
}

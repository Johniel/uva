#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int H = 1000, W = 1000;
static const int INF = 1 << 30;

struct Edge{
  int i, j, cost;
  Edge(int _i, int _j, int c)
    : i(_i), j(_j), cost(c) {}
};

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.i != b.i)return a.i > b.i;
  return a.j > b.j;
}

static int F[H][W];

inline 
bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

inline
int SSSP(int cs, int rs, int cd, int rd, int h, int w)
{
  static const int adj = 8;
  static const int di[] = {-1, -1, 0, 1, 1,  1,  0, -1};
  static const int dj[] = { 0,  1, 1, 1, 0, -1, -1, -1};
  static int cost[H][W];
  static bool visited[H][W];
  priority_queue<Edge> Q;    
  fill(&cost[0][0], &cost[h-1][w], INF); 
  fill(&visited[0][0], &visited[h-1][w], false);
  cost[cs][rs] = 0;
  for(Q.push(Edge(cs, rs, 0)); !Q.empty() && !visited[cd][rd];){
    Edge n = Q.top();
    Q.pop();
    if(visited[n.i][n.j])continue;
    visited[n.i][n.j] = true;
    REP(d, adj){
      int ni = n.i + di[d];
      int nj = n.j + dj[d];
      if(!isIn(ni, nj, h, w))continue;
      int tmp = (d == F[n.i][n.j])? 0 : 1;
      tmp += n.cost;
      if(cost[ni][nj] <= tmp)continue;     
      cost[ni][nj] = tmp;
      Q.push(Edge(ni, nj, tmp));
    }
  }
  return cost[cd][rd];
}

int main(void)
{
  int h, w;
  int rs, cs, rd, cd;
  int n;
  while(scanf("%d%d", &h, &w) == 2){
    REP(i, h){      
      REP(j, w){
	char c;
	scanf(" %c", &c);
	F[i][j] = c - '0';
      }
    }
    scanf("%d", &n);
    REP(i, n){
      scanf("%d%d%d%d", &cs, &rs, &cd, &rd);
      printf("%d\n", SSSP(cs-1, rs-1, cd-1, rd-1, h, w));
    }
  }
  return 0;
}

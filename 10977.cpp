#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int H = 200, W = 200, ADJ = 4, INF = 1 << 20, BLOCK = -1;
static const int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};

static bool visited[H][W];

inline bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

int sssp(const int h, const int w)
{ 
  static int dist[H][W];
  fill(&dist[0][0], &dist[h-1][w], INF);
  queue< pair<int, int> > Q;
  if(visited[0][0])return -1;
  dist[0][0] = 0;
  for(Q.push(make_pair(0, 0)); !Q.empty(); Q.pop()){
    pair<int, int> n = Q.front();
    if(n.first == h-1 && n.second == w-1)break;
    REP(i, ADJ){
      int ni = n.first + di[i];
      int nj = n.second + dj[i];
      if(!isIn(ni, nj, h, w) || visited[ni][nj])continue;
      visited[ni][nj] = true;
      dist[ni][nj] = dist[n.first][n.second] + 1;
      Q.push(make_pair(ni, nj));
    }
  }
  return (dist[h-1][w-1] == INF)? -1 : dist[h-1][w-1];
}

inline bool reachable(int ni, int nj, int l)
{
  return ni * ni + nj * nj <= l * l;
}

int main(void)
{
  while(true){
    int h, w, n, r, c, len;
    cin >> h >> w;
    if(h == 0 && w == 0)break;
    fill(&visited[0][0], &visited[h-1][w], false);
    cin >> n;
    REP(i, n){
      cin >> r >> c;
      visited[r - 1][c - 1] = BLOCK;
    }
    cin >> n;
    REP(i, n){
      cin >> r >> c >> len;
      --r; --c;
      for(int lh = -len-1; lh <= len+1; ++lh){
	for(int lw = -len-1; lw <= len+1; ++lw){
	  int ni = r + lh;
	  int nj = c + lw;
	  if(isIn(ni, nj, h, w) && reachable(lh, lw, len))
	    visited[ni][nj] = BLOCK;
	}
      }
    }
    //cout << endl; REP(i, h){ REP(j, w)cout << visited[i][j]; cout << endl; }
    int result = sssp(h, w);
    if(result < 0)cout << "Impossible." << endl;
    else cout << result << endl;
  }
  return 0;
}

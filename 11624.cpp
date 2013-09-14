#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int H = 1000 + 1, W = 1000 + 1;

char g[H][W];

bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

int bfs(pair<int, int> src, vector< pair<int, int> > fire, int h, int w)
{
  const int adj = 4;
  const int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
  queue< pair<int, int> > J, F;
  J.push(src);
  FOR(i, fire){
    F.push(*i);
  }
  for(int lim, cnt = 0; !J.empty(); ++cnt){
    lim = J.size();
    REP(i, lim){
      pair<int, int> p = J.front();
      J.pop();
      if(g[p.first][p.second] == 'F')continue;
      REP(d, adj){
	int ni = p.first + di[d], nj = p.second + dj[d];
	if(!isIn(ni, nj, h, w))return cnt + 1; 
	if(g[ni][nj] != '.')continue;
	g[ni][nj] = 'V';
	J.push(make_pair(ni, nj));
      }
    }
    lim = F.size();
    REP(i, lim){
      pair<int, int> p = F.front();
      F.pop();
      REP(d, adj){
	int ni = p.first + di[d], nj = p.second + dj[d];
	if(!isIn(ni, nj, h, w))continue;
	if(g[ni][nj] == '#' || g[ni][nj] == 'F')continue;
	g[ni][nj] = 'F';
	F.push(make_pair(ni, nj));
      }
    }
  }
  return -1;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int h, w;
    cin >> h >> w;
    pair<int, int> src;
    vector< pair<int, int> > fire;
    REP(i, h){
      REP(j, w){
	cin >> g[i][j];
	if(g[i][j] == 'J')src = make_pair(i, j);
	if(g[i][j] == 'F')fire.push_back(make_pair(i, j));
      }
    }
    int result = bfs(src, fire, h, w);
    if(result < 0)cout << "IMPOSSIBLE" << endl;
    else cout << result << endl;
  }
  return 0;
}

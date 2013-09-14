#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second

using namespace std;

static const int H = 20, W = 20;

struct State{
  int a, b, c, d;
  State(){}
  State(int _a, int _b, int _c, int _d){
    a = _a;
    b = _b;
    c = _c;
    d = _d;
  }
};

char g[H][W];

bool isin(int i, int j, int h, int w)
{
  return !(i < 0 || j < 0 || h <= i || w <= j);
}

string bfs(pair<int, int> src, 
	   pair<int, int> dst, 
	   pair<int, int> box, 
	   int h, int w)
{
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};
  const char p[] = {'W', 'E', 'N', 'S'};
  const char b[] = {'w', 'e', 'n', 's'};
  queue<State> q;
  queue<State> r;
  static string path[H][W][H][W];
  fill(&path[0][0][0][0], &path[H-1][W-1][H-1][W], "");
  path[src.fr][src.sc][box.fr][box.sc] = "@";
  for(q.push(State(src.fr, src.sc, box.fr, box.sc)); q.size(); ){
    State n = q.front();
    q.pop();
    //cout << n.a << ' ' << n.b << ' ' << n.c << ' ' << n.d << endl;

    for(int d=0; d<4; ++d){
      int ni = n.a + di[d];
      int nj = n.b + dj[d];
      if(!isin(ni, nj, h, w))continue;
      if(g[ni][nj] == '#')continue;
      if(ni == n.c && nj == n.d){
	int mi = n.c + di[d];
	int mj = n.d + dj[d];
	if(!isin(mi, mj, h, w))continue;
	if(g[mi][mj] == '#')continue;
	if(path[ni][nj][mi][mj].size())continue;
	path[ni][nj][mi][mj] = path[n.a][n.b][n.c][n.d] + p[d];
	if(dst.fr == mi && dst.sc == mj){
	  return path[ni][nj][mi][mj];
	}
	r.push(State(ni, nj, mi, mj));
      }
      else{
	if(path[ni][nj][n.c][n.d].size())continue;
	//if(g[ni][nj] == 'T')continue;
	path[ni][nj][n.c][n.d] = path[n.a][n.b][n.c][n.d] + b[d];
	q.push(State(ni, nj, n.c, n.d));
      }
    }
    if(q.empty()){
      while(r.size()){
	q.push(r.front());
	r.pop();
      }
    }
  }
  return "@Impossible.";
}

int main(void)
{
  int w, h;
  while(cin >> h >> w && h){
    pair<int, int> src, dst, box;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
	cin >> g[i][j];
	if(g[i][j] == 'S')src = make_pair(i, j);
	if(g[i][j] == 'T')dst = make_pair(i, j);
	if(g[i][j] == 'B')box = make_pair(i, j);
      }
    }    
    /*
    g[src.fr][src.sc] = '.';
    g[dst.fr][dst.sc] = '.';
    g[box.fr][box.sc] = '.';
    */
    string r = bfs(src, dst, box, h, w);
    r.erase(r.begin());
    static int cnt = 0;
    cout << "Maze #" << ++cnt << endl;
    cout << r << endl;
    cout << endl;
  }
  return 0;
}

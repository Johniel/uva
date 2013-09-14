#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int H = 20, W = 20;

typedef pair<int, int> Point;

struct State{
  queue<Point> snake;
  Point h;
  int cnt, n, egg;
  char g[H][W];  
  State(){ 
    cnt = 0; 
    fill(&g[0][0], &g[H-1][W-1], 'x');
  }
};

inline bool operator < (State a, State b)
{
  for(int i=0; i<a.n; ++i){
    for(int j=0; j<b.n; ++j){
      if(a.g[i][j] != b.g[i][j]){
	return a.g[i][j] < b.g[i][j];
      }
    }
  }
  return false;
}

inline bool isIn(int &i, int &j, int &h, int &w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

inline int bfs(State &ini)
{
  const int adj = 4;
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};
  set<State> visited;
  queue<State> q;
  visited.insert(ini);
  for(q.push(ini); !q.empty(); q.pop()){    

    //test(q.front());

    for(int d=0; d<adj; ++d){
      State s = q.front(); 
      int ni = s.h.first + di[d];
      int nj = s.h.second + dj[d];
      if(!isIn(ni, nj, s.n, s.n))continue;
      if(s.g[ni][nj] != '-' && s.g[ni][nj] != 'o')continue;
      if(s.g[ni][nj] == 'o'){
	if(--s.egg == 0)return s.cnt + 1;
      }
      else{
	Point p = s.snake.front();
	s.g[p.first][p.second] = '-';
	s.snake.pop();
      }
      s.snake.push(make_pair(ni, nj));
      ++s.cnt;
      s.g[ni][nj] = '*';
      s.h = make_pair(ni, nj);
      if(visited.count(s))continue;
      q.push(s);
      visited.insert(s);
    }
  }
  return -1;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int n;
    State s;
    cin >> n;
    s.n = n;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	cin >> s.g[i][j];
      }
    }
    s.g[0][0] = '*';
    s.snake.push(make_pair(0, 0));
    s.h = s.snake.front();
    s.egg = count(&(s.g[0][0]), &(s.g[n-1][n]), 'o');
    int result = bfs(s);
    if(result == -1)cout << "NO" << endl;
    else cout << result << endl;
    if(tc)cout << endl;
  }
  return 0;
}

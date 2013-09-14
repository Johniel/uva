 #include <iostream>
#include <algorithm>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;

struct State{
  int i, j;
  string path;
};

const int MAZE = 6;
const int UP = 1, DOWN = 2, RIGHT = 4, LEFT = 8;
const int MSK[] = {LEFT, RIGHT, UP, DOWN};
const char dir[] = {'W', 'E', 'N', 'S'};

int maze[MAZE][MAZE];

inline
bool is_inside(int i, int j)
{
  return !(i < 0 || MAZE <= i || j < 0 || MAZE <= j);
}

string bfs(pair<int, int> src, pair<int, int> dst)
{
  const int adj = 4;
  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};  
  static bool visited[MAZE][MAZE];  
  queue<State> q;
  fill(&visited[0][0], &visited[MAZE-1][MAZE], false);
  visited[src.fr][src.sc] = true;
  State ini;
  ini.i = src.fr;
  ini.j = src.sc;  
  for(q.push(ini); !q.empty(); q.pop()){
    State p = q.front();

    //cout << p.i << ' ' << p.j << ' ' << p.path << endl;

    if(p.i == dst.fr && p.j == dst.sc){
      return p.path;      
    }
    REP(d, adj){
      if(maze[p.i][p.j] & MSK[d])continue;
      int ni = p.i + di[d];
      int nj = p.j + dj[d];
      if(!is_inside(ni, nj))continue;
      if(visited[ni][nj])continue;
      State n = p;
      n.path += dir[d];
      n.i = ni;
      n.j = nj;
      visited[ni][nj] = true;
      q.push(n);
    }
  }
  return "error";
}

int main(void)
{
  pair<int, int> src, dst;
  while(cin >> src.sc >> src.fr >> dst.sc >> dst.fr){
    fill(&maze[0][0], &maze[MAZE-1][MAZE], 0);
    --src.sc;
    --src.fr;
    --dst.sc;
    --dst.fr;
    REP(k, 3){
      pair<int, int> a, b;
      cin >> a.sc >> a.fr >> b.sc >> b.fr;
      if(a.fr == b.fr){
	if(a.fr == 0 || a.fr == MAZE)continue;
	int lim = max(a.sc, b.sc);
	for(int i=min(a.sc, b.sc); i<lim; ++i){
	  maze[a.fr][i] |= UP;
	  maze[a.fr-1][i] |= DOWN;
	}
      }
      if(a.sc == b.sc){
	if(a.sc == 0 || a.sc == MAZE)continue;
	int lim = max(a.fr, b.fr);
	for(int i=min(a.fr, b.fr); i<lim; ++i){
	  maze[i][a.sc] |= LEFT;
	  maze[i][a.sc-1] |= RIGHT;
	}
      }
    }
    /*
    REP(i, MAZE){
      REP(j, MAZE){
	cout << maze[i][j] << ' ' ;
      }
      cout << endl;
    }
    */
    cout << bfs(src, dst) << endl;
  }
  return 0;
}

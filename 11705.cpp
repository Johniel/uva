#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 50 + 1;

struct state{
  int d;
  pair<int, int> n, p;
  state(int nf, int ns, int pf, int ps, int depth){
    n.first = nf;
    n.second = ns;
    p.first = pf;
    p.second = ps;
    d = depth;
  }
};

bool operator < (const state &a, const state &b)
{
  if(a.d != b.d)return a.d > b.d;
  if(a.n.first != b.n.first)return a.n.first < b.n.first;
  if(a.n.second != b.n.second)return a.n.second < b.n.second;
  if(a.p.first != b.p.first)return a.p.first > b.p.first;
  return a.p.second > b.p.second;
}

static int L[NODE][NODE];
static char D[NODE][NODE];

inline bool isIn(int ni, int nj, int h, int w)
{
  return !(ni < 0 || h <= ni || nj < 0 || w <= nj);
}

inline void decideDir(state s)
{
  if(s.n.first == s.p.first){
    if(s.n.second < s.p.second)
      D[s.n.first][s.n.second] = 'E';
    else
      D[s.n.first][s.n.second] = 'W';
  }
  else{
    if(s.n.first < s.p.first)
      D[s.n.first][s.n.second] = 'S';
    else
      D[s.n.first][s.n.second] = 'N';
  }
  return ;
}

void visitBFS(int h, int w)
{
  static const int adj = 4;
  static const int di[] = { 0, -1, 1, 0};
  static const int dj[] = {-1,  0, 0, 1};
  static bool visited[NODE][NODE];
  priority_queue<state> Q;
  fill(&visited[0][0], &visited[h-1][w], false);
  for(Q.push(state(0, 0, 0, 0, 0)); !Q.empty();){
    state s = Q.top(); 
    Q.pop();
    if(visited[s.n.first][s.n.second])continue;
    visited[s.n.first][s.n.second] = true;
    decideDir(s);
    REP(d, adj){
      REP(f, (1 << 20)){
	int ni = s.n.first  + f * di[d];
	int nj = s.n.second + f * dj[d];
	if(!isIn(ni, nj, h, w))break;
	if(f != L[ni][nj] || visited[ni][nj])continue;
	//cout<<'('<<s.n.first<<","<<s.n.second<<")=>("<<ni<<","<<nj<<")"<<endl; 
	Q.push(state(ni, nj, s.n.first, s.n.second, s.d + 1));
      }
    }
  }
  return ;
}

int main(void)
{
  while(true){    
    int h, w;
    cin >> h >> w;
    if(h == 0 && w == 0)
      break;
    fill(&D[0][0], &D[h][w], 'X');
    REP(i, h){
      REP(j, w)
	cin >> L[i][j];
    }
    visitBFS(h, w);
    D[0][0] = '*';
    REP(i, h){
      REP(j, w)
	cout << D[i][j];
      cout << endl;
    }
    cout << endl;
  }    
  return 0;
}

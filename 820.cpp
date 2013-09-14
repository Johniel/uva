//flow
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const static int N = 100;

int field[100][100];

int EdmondsKarp(int n, int s, int t)//n:GraphSize, s:start, t:goal
{
  int flow[n][n];
  fill(&flow[0][0], &flow[n-1][n], 0);
  int re = 0;
  while(true){ 
    int from[n];
    fill(from, from + n, -1);
    from[s] = s;
    queue<int> que;
    for(que.push(s); !que.empty(); que.pop()){
      if(from[t] != -1)break;
      int i = que.front();
      REP(j, n)if(from[j] < 0 && 0 < field[i][j] - flow[i][j]){
	from[j] = i;
	que.push(j);
      } 
    }

    //REP(i, n)cout << from[i] << ' ' ;cout << endl;

    if(from[t] < 0)break;
    int cst = 1 << 20;
    for(int i=t; from[i] != i; i=from[i])
      cst = min(cst, field[from[i]][i] - flow[from[i]][i] );
    for(int i=t; from[i] != i; i=from[i])
      flow[from[i]][i] += cst;
    re += cst;
  }
  return re;
}


int main(void)
{
  int tc = 0;
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    int s, t, c;
    cin >> s >> t >> c;
    fill(&field[0][0], &field[n-1][n], 0);
    REP(i, c){
      int to, from, cst;
      cin >> to >> from >> cst;
      field[to-1][from-1] = field[from-1][to-1] += cst;
    }
    cout << "Network " << ++tc << endl;
    cout << "The bandwidth is " << EdmondsKarp(n, s-1, t-1) << '.' << endl;
    cout << endl;
  }
  return 0;
}

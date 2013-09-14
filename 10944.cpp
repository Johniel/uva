#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

static const int MAX = 20;
static const int NUTS = 16;
static const int INF = 1<<20;

const int ADJ = 8;
const int ni[ADJ] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int nj[ADJ] = {-1,  0,  1, -1, 1, -1, 0, 1};

int G[NUTS][NUTS];
int no[MAX][MAX];
int cost[NUTS][1<<NUTS], P[NUTS][1<<NUTS];//, p[n];

int TSP(const int start, const int n)
{
  const int size = 1<<n;
  fill(&cost[0][0], &cost[n-1][size], INF);
  fill(&P[0][0], &P[n-1][size], -1);
  REP(i, n)cost[i][1<<i] = G[start][i];
  for(int s=1; s<size; s++){
    REP(i, n){
      if(!(s & (1<<i)))continue;
      REP(j, n){
        if(s & (1<<j))continue;
        if(cost[i][s] + G[i][j] < cost[j][s|(1<<j)]){
          cost[j][s|(1<<j)] = cost[i][s] + G[i][j];
          P[j][s|(1<<j)] = i;
        }
      }
    }
  }
  return cost[start][size-1];
}

void BFS(const int p, const pair<int, int> ini, const int height, const int width)
{
  bool visited[MAX][MAX];
  queue< pair< pair<int, int>, int > > Q;
  fill(&visited[0][0], &visited[height-1][width], false);
  visited[ini.first][ini.second] = true;
  for(Q.push(make_pair(ini, 0)); !Q.empty(); Q.pop()){
    pair<int, int> point = Q.front().first;
    int cnt = Q.front().second;
    int i = point.first, j = point.second;
    REP(s, ADJ){
      int si = i + ni[s], sj = j + nj[s];
      if(0 <= si && si < height && 0 <= sj && sj < width){
        if(visited[si][sj])continue;
        if(no[si][sj] != -1 && no[si][sj] != p)
          G[p][no[si][sj]] = cnt+1;
        visited[si][sj] = true;
        Q.push(make_pair(make_pair(si, sj), cnt+1));
      }
    }
  }
  return ;
}


int main(void)
{
  int width, height, cnt, s;
  char c;
  while(true){
    cin >> height >> width;
    if(cin.eof())break;
    cnt = 0;
    pair<int, int> nuts[16];
    fill(&no[0][0], &no[height-1][width], -1);
    /*
    REP(i, height)REP(j, width){
      cin >> c;
      if(c == 'L'){
        no[i][j] = 0;
        s = cnt++;
      }
      else if(c != '.')no[i][j] = cnt++;
    }
    REP(i, height)REP(j, width)
      if(no[i][j] != -1)BFS(no[i][j], make_pair(i, j), height, width);
    */
    REP(i, height)REP(j, width){
      cin >> c;
      if(c == 'L'){
       	nuts[cnt].first = i;
	nuts[cnt].second = j;
        s = cnt++;
      }
      else if(c != '.'){
	nuts[cnt].first = i;
	nuts[cnt].second = j;
	cnt++;
      }
    }
    REP(i, cnt-1)for(int j=i+1; j<cnt; j++)
      G[i][j] = G[j][i] = max(abs(nuts[i].first - nuts[j].first), abs(nuts[i].second - nuts[j].second));
    //cout << s << ' '<< cnt << endl;
    //REP(i, cnt){REP(j, cnt)cout << G[i][j] << ' ' ;cout << endl;}
    cout << TSP(s, cnt) << endl;
  }
  return 0;
}

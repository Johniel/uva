#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;

const int G = 50;

const int adj = 4;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

char g[G][G];
int no[G][G];
int visited[G][G];

bool inside(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

void group(int i, int j, int n, int m)
{
  no[i][j] = m;
  REP(d, adj){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(!inside(ni, nj, n, n))continue;
    if(g[ni][nj] == '.')continue;
    if(no[ni][nj])continue;
    group(ni, nj, n, m);
  }
  return ;
}

struct Sector{
  int b, p, adj;
  Sector(){
    b = p = adj = 0;
  }
};

int test;
set< pair< pair<int, int>, pair<int, int> > > fight, rem;
void rec(int i, int j, char c, map<int, Sector> &result, int n)
{
  visited[i][j] = test;
  REP(d, adj){
    int ni = i + di[d];
    int nj = j + dj[d];
    if(!inside(ni, nj, n, n))continue;
    if(g[ni][nj] == '.' || g[ni][nj] == '*')continue;
    if(g[ni][nj] != c){
      pair<int, int> p = make_pair(i, j);
      pair<int, int> q = make_pair(ni, nj);
      fight.insert(make_pair(p, q));
      continue;
    }
    if(visited[ni][nj])continue;
    rec(ni, nj, c, result, n);
  }
  return ;
}

int main(void)
{  
  for(int n; cin >> n; ){
    if(n == 0)break;
    REP(i, n){
      REP(j, n){
	cin >> g[i][j];
	no[i][j] = visited[i][j] = 0;
      }
    }

    int cnt = 0;
    REP(i, n){
      REP(j, n){
	if(g[i][j] == '.' || no[i][j])continue;
	group(i, j, n, ++cnt);
      }
    }

    map<int, Sector> result;
    test = 0;
    REP(i, n){
      REP(j, n){	
	if(g[i][j] == '.' || g[i][j] == '*' || visited[i][j])continue;
	++test;
	rec(i, j, g[i][j], result, n);
	if(g[i][j] == 'B')++result[no[i][j]].b;
	if(g[i][j] == 'P')++result[no[i][j]].p;
      }
    }
    set<int> tmp;
    FOR(i, fight){
      pair<int, int> p = i->first;
      pair<int, int> q = i->second;
      tmp.insert(visited[p.first][p.second]);
      tmp.insert(visited[q.first][q.second]);
    }

    FOR(i, result){
      printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n", 
	     i->first, i->second.b, i->second.p);
    }
    printf("Total %d group(s) are in fighting position.\n", tmp.size());
    puts("");
    fight.clear();
    rem.clear();

    //REP(i, n){REP(j, n)cout << g[i][j] ;cout << endl;}
    //REP(i, n){REP(j, n)cout << no[i][j] << ' ';cout << endl;}cout << endl;
    //REP(i, n){REP(j, n)cout << visited[i][j] << ' ';cout << endl;}cout << endl;
  }
  return 0;
}

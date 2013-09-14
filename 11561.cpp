#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int MAX = 50 + 1;

static const char VISITED = '@';

static char F[MAX][MAX];
static bool T[MAX][MAX];

const int adj = 4;
const int di[] = { 0, 0, -1, 1};
const int dj[] = {-1, 1,  0, 0};

int result;

inline
bool isIn(int i, int j, int h, int w)
{
  return !(i < 0 || h <= i || j < 0 || w <= j);
}

inline
void putTrap(int i, int j, int h, int w)
{
  //cout << i << ' ' << j << endl;
  REP(k, adj){
    int ni = i + di[k], nj = j + dj[k];
    if(isIn(ni, nj, h, w)){
      T[ni][nj] = true;
      //cout << "trap : " << ni << ' ' << nj << endl;
    }
  }
  return ;
}

void visitDFS(int pi, int pj, int h, int w)
{ 
  if(F[pi][pj] == 'G')++result;
  F[pi][pj] = VISITED;
  if(T[pi][pj])return ;
  REP(i, adj){
    int ni = pi + di[i], nj = pj + dj[i];
    if(!isIn(ni, nj, h, w) || 
       F[ni][nj] == VISITED || 
       F[ni][nj] == '#')continue;
    visitDFS(ni, nj, h, w);
  }
  return ;
}

int main(void)
{
  int h, w, si, sj;
  while(cin >> w >> h){
    result = 0;
    fill(&T[0][0], &T[h-1][w], false);
    REP(i, h){
      REP(j, w){
	cin >> F[i][j];
	if(F[i][j] == 'T')
	  putTrap(i, j, h, w);
	else if(F[i][j] == 'P'){
	  si = i;
	  sj = j;
	}
      }
    }
    //REP(i, h){REP(j, w)cout << F[i][j];cout << endl;}cout << endl;
    //REP(i, h){REP(j, w)cout << T[i][j];cout << endl;}
    visitDFS(si, sj, h, w);
    cout << result << endl;
  }
  return 0;
}

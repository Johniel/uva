//recursive
#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; i++)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef struct{
  char c;
  int n;
}data;

int h, w;

const int M = 10000;

char field[M][M];
char BLOCK = '#';

const int N = 4;
int ni[] = { 0, 0, -1, 1};
int nj[] = {-1, 1,  0, 0};

void bfs(int i, int j, char c)
{
  REP(a, N){
    int si = i + ni[a];
    int sj = j + nj[a];
    if(0 <= si && si < h && 0 <= sj && sj < w){
      if(field[si][sj] == c ){
	field[si][sj] = BLOCK;
	bfs(si, sj, c);
      }
    }
  }
  return ;
}

bool cmp(data a, data b)
{
  if(a.n == b.n)return (a.c < b.c);
  return (a.n > b.n);
}

int main(void)
{
  int tc, round = 0;
  cin >> tc;
  while(tc--){
    string rem;
    cin >> h >> w;
    REP(i, h)REP(j, w){
      cin >> field[i][j];
      if(count(ALL(rem), field[i][j]))
	continue;
      rem += field[i][j];
    }
    int p = 0;
    data re[rem.size()];
    //cout << "World #" << ++round << endl;
    REP(k, rem.size()){
      int cnt = 0;
      REP(i, h)REP(j, w){
	if(field[i][j] == rem[k]){
	  field[i][j] = BLOCK;
	  bfs(i, j, rem[k]);
	  cnt++;
	}
      } 
      re[p].n = cnt;
      re[p].c = rem[k];
      p++;
	//cout << rem[k] << ": " << cnt << endl;
	}
    sort(re, re + rem.size(), cmp);
    cout << "World #" << ++round << endl;
    REP(i, rem.size())
      cout << re[i].c << ": " << re[i].n << endl;
  }
  return 0;
}

#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

const int N = 20000 + 1, COIN = 100, INF = 1 << 20;
int coin[COIN], t[COIN][N], visited[COIN][N];

inline
void dp(int p, int n)
{  
  fill(&t[0][0], &t[COIN-1][N], INF);
  fill(&visited[0][0], &visited[COIN-1][N], false);

  t[0][coin[0]] = 1;
  for(int i=1; i<n; ++i){// coin type
    for(int j=0; j<N; ++j){      
      t[i][j] = min(t[i][j], t[i-1][j]); 
      if(j + coin[i] < N){	  
	t[i][j + coin[i]] = min(t[i][j + coin[i]], t[i-1][j] + 1);
      }
    }
    t[i][coin[i]] = 1;
  }
  //#define TEST
#ifdef TEST
  for(int j=0; j<110+1; ++j){
    printf("%3d", j);
  }
  puts("\n");
  for(int i=0; i<n; ++i){
    for(int j=0; j<110+1; ++j){
      if(t[i][j] != INF)printf("%3d", t[i][j]);
      else printf("  0");
    }
    puts("\n");
  }
  puts("\n");
#endif
  for(int i=p; i<N; ++i){
    if(t[n-1][i] != INF){
      cout << i << ' ' << t[n-1][i] << endl;
      break;
    }
  }
  return ;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int p, n;
    cin >> p >> n;
    for(int i=0; i<n; ++i){
      cin >> coin[i];
    }
    sort(coin, coin + n);
    dp(p, n);
  }
  return 0;
}

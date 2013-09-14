#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int N = 15;

char board[N][N];

int solve(int mask)
{
  static char tmp[N][N];
  int cnt = 0;
  copy(&board[0][0], &board[N-1][N], &tmp[0][0]);  
  REP(i, N){
    if(mask & (1 << i)){
      ++cnt;
      REP(j, N){
	tmp[i][j] = '.';	
      }
    }
  }
  int ex = 0;
  REP(j, N){
    REP(i, N){
      if(tmp[i][j] == '#'){
	++ex;
	break;
      }
    }
  }
  return ex <= cnt? cnt : 1 << 20;
}

int main(void)
{
  while(true){
    REP(i, N){
      REP(j, N){
	cin >> board[i][j];
	if(board[i][j] != '.' && 
	   board[i][j] != '#'){
	  return 0;
	}
      }
    }
    int ans = 1 << 20;
    REP(i, 1 << 16){
      ans = min(ans, solve(i));
    }
    cout << ans << endl;
  }
  return 0;
}

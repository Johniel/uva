#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000007; 
const int N = 10 + 1, M = 100 + 1;
const int BIT = 1 << 11;

int dp(int n, int m)
{
  static int t[M][N][BIT];
  int bit = 1 << n; 
  fill(&t[0][0][0], &t[m][n][bit], 0);
  for(int i=0; i<n; ++i){
    t[0][i][1 << i] = 1;
  }
  for(int i=0; i<m; ++i){
    for(int j=0; j<n; ++j){
      for(int k=0; k<bit; ++k){
	if(t[i][j][k] == 0)continue;
	int a = j + 1;
	int b = j - 1;
	if(a != n){
	  t[i + 1][a][k | (1 << a)] += t[i][j][k];
	  t[i + 1][a][k | (1 << a)] %= MOD;
	}
	if(-1 < b){
	  t[i + 1][b][k | (1 << b)] += t[i][j][k];
	  t[i + 1][b][k | (1 << b)] %= MOD;
	}
      }
    }
  }
  int sum = 0;
  for(int i=0; i<m; ++i){
    for(int j=1; j<n; ++j){
      sum += t[i][j][bit - 1];
      sum %= MOD;
    }
  }
  return sum;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--;){
    int n, m;
    cin >> n >> m;
    cout << dp(n, m) << endl;
  }
  return 0;
}

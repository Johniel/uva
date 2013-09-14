#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10 + 1;
const int K = 1000 + 1;
const int D = 30 + 1;

int g[N][N][D];
int t[N][K];
int len[N][N];
const int inf = 1 << 24;

int dp(int n, int k)
{
  fill( &t[0][0], &t[N-1][K], inf );
  t[0][0] = 0;
  for(int d=1; d<=k; ++d){
    for(int src = 0; src < n; ++src){
      if( t[src][d-1] == inf )continue;
      for(int dst = 0; dst < n; ++dst){
        if( src == dst )continue;
        int c = (d - 1) % len[src][dst];
        c = g[src][dst][c];
        if( c == 0 )continue;
        t[dst][d] = min( t[dst][d], t[src][d-1] + c );
      }
    }
  }
  /*
  for(int i=0; i<=n; ++i){
    for(int j=0; j<=k; ++j){
      if( t[i][j] != inf )cout << i << "," << j << " : " << t[i][j] << endl;
    }
  }
  */
  int tmp = t[n-1][k];
  return tmp == inf ? -1 : tmp;
}

int main(void)
{
  int cnt = 0;
  int n, k;
  while( cin >> n >> k && (n | k) ){
    fill( &g[0][0][0], &g[N-1][N-1][D], 0 );
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
        if( i == j )continue;
        cin >> len[i][j];
        for(int k=0; k<len[i][j]; ++k){
          cin >> g[i][j][k];
        }
      }
    }
    int r = dp(n, k);
    cout << "Scenario #" << ++cnt << endl;
    if(r < 0)cout << "No flight possible." << endl;
    else cout << "The best flight costs " << r << "." << endl;
    cout << endl;
  }
  return 0;
}

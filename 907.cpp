#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 1 << 23;

const int N = 600 + 2;
const int K = 300 + 1;
int t[N][K];
int cost[N];
int n, k;

int rec(int i, int j, int sum)
{
  if(k < j)return inf;
  if(n + 1 == i){
    if( j == k )return sum;
    else return inf;
  }
  if( t[i][j] != inf )return t[i][j];
  int a = rec(i + 1, j + 0, sum + cost[i]);
  int b = max(sum, rec(i + 1, j + 1, 0 + cost[i]));
  cout << i << ' ' << j << " : " << min(a, b) << endl;
  return t[i][j] = min(a, b);
}

int dp(void)
{
  fill(&t[0][0], &t[N-1][K], -inf);
  t[0][0] = 0;
  for(int i=0; i<=k; ++i){
    for(int j=0; j<=n; ++j){
      if( t[i][j] == -inf )continue;
      t[i+1][j] = max(t[i+1][j], t[i][]);
    }
  }
}

int main(void)
{
  while( cin >> n >> k ){
    fill(&t[0][0], &t[N-1][K], inf);
    for(int i=0; i<n+1; ++i){
      cin >> cost[i];
    }
    cout << rec(0, 0, 0) << endl;
  }
  return 0;
}

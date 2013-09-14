#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;

const int W = 32 + 1;
const int M = W * 20 + 1;
int w[W], sum;
int memo[W][M][M];

int rec(int s, int t, int d, int lim)
{  
  int a = max(s, t);
  int b = min(s, t);
  int mn = 1 << 22;
  
  if(memo[d][a][b] != -1)return memo[d][a][b];
  if(d == lim){
    int c = sum - a - b;
    return max(a, c) - min(b, c);
  }

  mn = min(mn, rec(a, b, d + 1, lim));
  mn = min(mn, rec(a + w[d], b, d + 1, lim));
  mn = min(mn, rec(a, b + w[d], d + 1, lim));

  return memo[d][a][b] = mn;
}

int solve(int size)
{
  sum = accumulate(w, w + size, 0);
  fill(&memo[0][0][0], &memo[size][sum][sum+1], -1);
  int r = rec(0, 0, 0, size);
  return r;
}

#include <cstdio>
int main(void)
{
  int tc, cnt = 0, n;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
      scanf("%d", w + i);
    }
    printf("Case %d: %d\n", ++cnt, solve(n));
  }
  return 0;
}

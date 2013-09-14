#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
#define each(i, c) FOR(i, c)

typedef long long int lli;

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  cin >> tc;
  while (tc--) {
    const int C = 4;
    int c[C];
    int d[C];
    for (int i = 0; i < C; ++i) {
      cin >> c[i];
    }
    int q;
    cin >> q;
    while (q--) {
      for (int i = 0; i < C; ++i) {
        cin >> d[i];
      }
      int v;
      cin >> v;

      const int V = 10000 + 1;
      lli dp[C + 1][V];

      lli sum = 0;

      for (int bit = 0; bit < (1 << 4); ++bit) {
        fill(&dp[0][0], &dp[C][V], 0);
        dp[0][0] = 1;

        for (int i = 0; i + 1 < C; ++i) {
          if (bit & (1 << i)) {
            for (int j = 0; j < V; ++j) {
              if (dp[i][j] == 0) continue;
              for (int k = 1; k <= d[i]; ++k) {
                if (j + k * c[i] < V) {
                  dp[i][j] += dp[i][j + k * c[i]];
                } else {
                  break;
                }
              }
            }
          } else {
            for (int j = 0; j < V; ++j) {
              dp[i + 1][j] = dp[i][j];
            }
          }
        }

        sum += dp[C][v];
      }

      cout << sum << endl;
    }
  }
  return 0;
}

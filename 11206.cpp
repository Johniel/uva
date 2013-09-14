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

#define VAR(a) cout << #a << " : " << a << endl;
#define LOG()  cout << __LINE__ << ", " << __func__ << endl;

typedef long long int lli;

using namespace std;

const int N = 1000;
int color[N];

const int C = 4;
int w[C];

vector<int> g[N];

bool valid(int src, int c)
{
  for (int i = 0; i < g[src].size(); ++i) {
    int dst = g[src][i];
    if (color[dst] == c) return false;
  }
  return true;
}

int get_value(int size)
{
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      int src = i;
      int dst = g[i][j];
      if (src < dst) {
        int diff = color[src] - color[dst];
        sum += diff * diff;
      }
    }
  }
  return sum;
}

int rec(int node, int size)
{
  if (node == size) {
    return get_value(size);
  }
  int mx = 0;
  for (int i = 0; i < C; ++i) {
    if (!valid(node, w[i])) continue;
    color[node] = w[i];
    mx = max(mx, rec(node + 1, size));
    color[node] = -1;
  }
  return mx;
}

int main(int argc, char *argv[])
{
  int node, edge;
  while (cin >> node >> edge) {
    fill(g, g + N, vector<int>());

    for (int i = 0; i < C; ++i) {
      cin >> w[i];
    }

    for (int i = 0; i < edge; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    fill(color, color + N, -1);
    cout << rec(0, node) << endl;
  }
  return 0;
}

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

const int N = 10;
int T[N];

inline
int get_sub(int n, int begin, int end)
{
  return n % T[end] / T[begin];
}

inline
pair<int, int> cut(int n, int begin, int end, int len)
{
  int a = get_sub(n, begin, end);
  int b = get_sub(n, 0, begin) + get_sub(n, end, len) * T[begin];
  return make_pair(a, b);
}

inline
int insert(int n, int len, int p, int s, int len2)
{
  int a = get_sub(n,0,p);
  int b = get_sub(n,p,len);
  return a + s * T[p] + b * T[p+len2];
}

inline
int make_next(int n, int begin, int end, int k, int len)
{
  pair<int, int> p = cut(n, begin, end, len);
  int sl = end - begin;
  int bl = len - sl;
  return insert(p.second, bl, k, p.first, sl);
}

inline
int make_dst(int n)
{
  int m = 0;
  for (int i = 0; i < n; ++i) {
    m = m * 10 + i;
  }
  return m;
}

map<int, int> backward[N];
void bfs1(int n)
{
  assert(backward[n].empty());

  int ini = make_dst(n);

  map<int, int> &cost = backward[n];
  queue<int> q;
  cost[ini] = 0;

  for (q.push(ini); q.size(); q.pop()) {
    int curr = q.front();
    if (cost[curr] == 4) continue;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        for (int k = 0; k <= n - (j - i); ++k) {
          int next = make_next(curr, i, j, k, n);
          if (cost.count(next)) continue;
          cost[next] = cost[curr] + 1;
          q.push(next);
        }
      }
    }
  }
  return ;
}

int bfs2(int ini, int n)
{
  map<int, int> &rev = backward[n];
  map<int, int> cost;
  queue<int> q;
  cost[ini] = 0;

  int dst = make_dst(n);

  for (q.push(ini); q.size(); q.pop()) {
    int curr = q.front();
    if (curr == dst) return cost[dst];
    if (rev.count(curr)) return cost[curr] + rev[curr];
    if (cost[curr] == 5) continue;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        for (int k = 0; k <= n - (j - i); ++k) {
          int next = make_next(curr, i, j, k, n);
          if (cost.count(next)) continue;
          cost[next] = cost[curr] + 1;
          q.push(next);
        }
      }
    }
  }

  return -1;
}

int main(int argc, char *argv[])
{
  T[0] = 1;
  for (int i = 1; i < N; ++i) {
    T[i] = 10 * T[i - 1];
  }

  int n;
  while (cin >> n && n) {
    int ini = 0;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      ini = ini * 10 + (m - 1);
    }
    static int tc = 0;
    if (backward[n].empty()) bfs1(n);
    cout << "Case " << ++tc << ": " << bfs2(ini, n) << endl;
  }

  return 0;
}

#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <deque>
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

int conv(char c)
{
  static const string C = "@ABCDEFGHIJKLMNOPQLSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  return C.find(c);
}

int main(int argc, char *argv[])
{
  string s;
  while (cin >> s) {
    string t = s;
    reverse(t.begin(), t.end());
    string u;

    const lli mod = 10000000000007LL;
    const lli p = 71;

    const int size = s.size();

    lli h;
    map<lli, int> len;
    int mx = 0;

    lli w[size];
    w[0] = 1;
    for (int i = 1; i < size; ++i) {
      w[i] = w[i - 1] * p;
      w[i] %= mod;
    }
    reverse(w, w + size);

    h = 0;
    for (int i = 0; i < size; ++i) {
      h = h * p + conv(t[i]);
      h %= mod;
      cout << "h2: " << h << endl;
      len[h] = i + 1;
    }
    h = 0;
    for (int i = 0; i < size; ++i) {
      h = h * p + conv(s[i]);
      cout << "h1: " << h << endl;
      h /= p;
    }

    for (int i = 0; i < size; ++i) {
      mx = max(mx, len[h]);
      h %= w[i];
    }

    cout << mx << endl;
  }
  return 0;
}

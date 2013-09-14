#include <iostream>

using namespace std;

static const int INF = 1 << 20;

int rec(int f, int e, const int br)
{
  int g = f;
  f = (g + e) / 3;
  e = (g + e) % 3;
  return (f + e < 3)? ((br <= e + f)? f + g : -INF) : g + rec(f, e, br);
}

int main(void)
{
  for(int n; cin >> n;)
    cout << max(rec(n, 0, 0), max(rec(n, 1, 1), rec(n, 2, 2))) << endl;
  return 0;
}

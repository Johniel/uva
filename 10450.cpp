#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <cassert>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

int main(void)
{
  lli t[51];
  t[1] = 2;
  t[2] = 3;
  for(int i=3; i<=50; ++i){
    t[i] = t[i-1] + t[i-2];
  }
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    cout << "Scenario #" << ++cnt << ":" << endl;
    cout << t[n] << endl;
    cout << endl;
  }
  return 0;
}

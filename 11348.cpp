#include <iostream>
#include <algorithm>
#include <set>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  int tc, test = 0;
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    map<int, int> M;
    set<int> S[n];
    for(int i=0; i<n; ++i){
      int m;
      cin >> m;
      for(int j=0; j<m; ++j){
	int name;
	cin >> name;
	if(S[i].count(name) == 0)++M[name];
	S[i].insert(name);
      }
    }
    int sum = 0;
    FOR(i, M){
      if(i->second == 1)sum++;
    }
    printf("Case %d:", ++test);
    REP(i, n){
      int cnt = 0;
      FOR(j, S[i])
	if(M[*j] == 1)cnt++;
      printf(" %lf%%", (double)cnt / (double)sum * 100.0);
    }
    printf("\n");
  }
  return 0;
}

#include <iostream>
#include <set>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  for(int n, m; cin >> n >> m; ){
    if(n == 0 && m == 0)break;
    map<int, int> S, T;
    set<int> vs, vt; 
    int num, cnt = 0;
    for(; n--; ){
      cin >> num;
      if(S[num]++)vs.insert(num);
    }
    for(; m--; ){
      cin >> num;
      ++T[num];
      if(T[num]++)vt.insert(num);
    }
    int r1 = 0, r2 = 0;
    FOR(i, S){
      if(!T.count(i->first))
	++r1;
    }
    FOR(i, T){
      if(!S.count(i->first))
	++r2;
    } 
    cout << min(r1, r2) << endl;
  }
  return 0;
}

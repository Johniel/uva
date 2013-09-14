#include <iostream>
#include <algorithm>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    set<int> p[3], wole, q[3];
    REP(i, 3){
      int n;
      cin >> n;
      REP(j, n){
	int m;
	cin >> m;
	p[i].insert(m);
	wole.insert(m);
      }
    }
    int m = -1;
    cout << "Case #" << ++cnt << ":" << endl;
    REP(i, 3){
      set<int> tmp, re = p[i];      
      REP(j, 3){
	if(i == j)continue;
	tmp.insert(ALL(p[j]));
      }
      FOR(j, tmp){
	if(re.count(*j))
	  re.erase(*j);
      }
      q[i] = re;
      m = max(m, (int)re.size());
    }
    REP(i, 3){
      if(q[i].size() == m){
	cout << i + 1 << ' ' << q[i].size();
	FOR(j, q[i])
	  cout << ' ' << *j;
	cout << endl;
      }
    }
  }
  return 0;
}

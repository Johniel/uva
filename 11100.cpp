#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

int main(void)
{
  const int N = 10000;
  int item[N];
  int n;
  bool flg = false;
  while(true){
    cin >> n;
    if(n == 0)break;
    if(flg)cout << endl;
    else flg = true;
    for(int i=0; i<n; ++i){
      cin >> item[i];
    }
    sort(item, item + n);
    for(int i=1; i<=n; ++i){
      int cnt = 0;
      vector<int> v[n];
      int j;
      for(j=0; j<n/i; ++j){
	for(int k=0; k<i; ++k){
	  if(v[j].back() < item[cnt]){
	    j = 1 << 20;
	    break;
	  }
	  v[j].push_back(item[cnt++]);
	}
      }
      if(j != (1 << 20)){
	REP(i, n){
	  FOR(j, v[i]){
	    if(j != v[i].begin())cout << ' ';
	    cout << *j;
	  }
	  cout << endl;
	}
      }
    }
  }
  return 0;
}

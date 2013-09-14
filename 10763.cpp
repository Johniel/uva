#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    map<int, int> M;
    for(int i=0; i<n; ++i){
      int src, dst;
      cin >> src >> dst;
      M[src] ^= 1;
      M[dst] ^= 1;
    }
    bool flg = true;
    FOR(i, M){
      //cout << i->first << ' ' << i->second << endl;
      if(i->second){
	flg = false;
	break;
      }
    }
    cout << (flg? "YES" : "NO") << endl;
  }
  return 0;
}

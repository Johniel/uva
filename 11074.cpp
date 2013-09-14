#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{                     
  int tc = 0;
  for(int s, t, n; ; ){
    cin >> s >> t >> n;
    if(s + t + n == 0)break;
    cout << "Case " << ++tc << ":" << endl;
    REP(i, t)cout << string(t + n * (s + t), '*') << endl;
    REP(i, n){
      REP(j, s){
	cout << string(t, '*');
	REP(k, n){
	  cout << string(s, '.');
	  cout << string(t, '*');	
	}
	cout << endl;
      }
      REP(i, t)cout << string(t + n * (s + t), '*') << endl;
    }
    cout << endl;
  }
  return 0;
}

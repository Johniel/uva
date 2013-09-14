#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  int tc, t, p;
  const int V = 101;
  bool g[V][V];
  cin >> tc;
  while(tc--){
    fill( &g[0][0], &g[V-1][V], false );
    cin >> p >> t;
    cin.ignore();
    for(string n; getline(cin, n) && n.size(); ){
      istringstream iss( n );
      int a, b;
      iss >> a >> b;
      --a;
      --b;
      g[ a ][ b ] = true;
    }    
    set<string> cnt;
    for(int i=0; i<p; ++i){
      string s;
      for(int j=0; j<t; ++j){
        if( g[i][j] )s += '\0' + j + 1;
      }
      cnt.insert( s );
    }

    cout << cnt.size() << endl;
    if(tc)cout << endl;
  }
  return 0;
}

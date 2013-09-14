#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  const int N = 5000 + 1;
  bool prime[N];
  int p[N], size = 0;
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j){
      prime[i*j] = false;
    }
  }
  for(int i=0; i<N; ++i){
    if(prime[i])p[size++] = i;
  }
  const int M = 10000 + 1;
  map<int, int> pf[M];
  for(int i=2; i<M; ++i){
    int n = i;
    for(int j=0; j<size; ++j){
      while( n % p[j] == 0 ){
        ++pf[i][p[j]];
        n /= p[j];
      }
    }
  }
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    int n, m;
    map<int, int> nf;
    cin >> m >> n;
    //cout << "m = " << m << " : " << "n = " << n << endl;
    cout << "Case " << ++cnt << ":" << endl;
    REP(i, n+1){
      FOR(j, pf[i]){
        nf[ j->first ] += j->second;
      }
    }
    bool flg = true;
    FOR(i, pf[m]){
      if( nf.find( i->first ) == nf.end() ) flg = false;
      else{
        if( i->second > nf[ i->first ] ){
          //cout << i->first << " : " << endl;
          //cout << "m  : " << i->second << endl;
          //cout << "n! : " << nf[ i->first ] << endl;
          flg = false;
        }
      }
    }
    if( !flg )cout << "Impossible to divide" << endl;
    else{
      /*
      cout << "n!" << endl;
      FOR(i, nf){
        cout << i->first << ' ' << i->second << endl;
      }
      cout << endl;
      cout << "m" << endl;
      FOR(i, pf[m]){
        cout << i->first << ' ' << i->second << endl;
      }
      */
      int mn = 1 << 24;
      FOR(i, pf[m]){
        int f = i->first;
        int a = nf[ f ];
        int b = i->second;
        int c = a / b;
        mn = min(mn, c);
      }
      cout << mn << endl;
    }
  }
  return 0;
}

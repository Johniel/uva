#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

int main(void)
{
  const int N = 4000;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j){
      prime[i*j] = false;
    }
  }
  static int p[N], p_size = 0;
  for(int i=0; i<N; ++i){
    if(prime[i])p[p_size++] = i;
  }
  
  vector<int> v;
  char buff[20];
  for(int i=0; i<p_size && p[i] < 1000; ++i){
    sprintf(buff, "%d", p[i]);
    string s(buff);
    bool flg = true;
    sort( s.begin(), s.end() );
    do{
      int n = atoi( s.c_str() );
      if(1000 < n){
        flg = false;
      }
      else flg = prime[n];
      if(!flg)break;
    }while( next_permutation( s.begin(), s.end() ) );
    if(flg)v.push_back( p[i] );
  }
  set<int> ap;
  for(int i=0; i<v.size(); ++i){
    sprintf(buff, "%d", v[i]);
    string s(buff);
    for(int j=0; j<s.size(); ++j){      
      ap.insert( atoi( s.c_str() ) );
      s += s[0];
      s.erase( s.begin() );
    }
  }

  int n;
  while(cin >> n && n){
    int lim = 1;
    while(lim <= n){
      lim *= 10;
    }
    set<int>::iterator i;
    int r = 0;
    for(i = ap.begin(); i != ap.end(); ++i){
      if(lim <= *i)break;
      if(n < *i){
        r = *i;
        break;
      }
      
    }
    cout << r << endl;
    /*
    i = upper_bound( ap.begin(), ap.end(), n );
    if( i == ap.end() )cout << 0 << endl;
    else{
      cout << *i << endl;
    }
    */
  }
  return 0;
}

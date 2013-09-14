#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

map< string, vector<string> > e;
map< pair< string, string >, pair< int, int > > rate;

inline int gcd(int a, int b){ return b?  gcd(b, a%b) : a; }

pair<int, int> rec(string v, string dst, set<string> &vis, pair<int, int> p)
{
  vis.insert( v );
  if( v == dst )return p;
  FOR(i, e[v]){
    if( vis.count(*i) )continue;
    pair<int, int> a = rate[ make_pair(v, *i) ];
    pair<int, int> b = p;
    a.first *= b.first;
    b.second *= a.second;
    int c = gcd( a.first, b.second );
    pair<int, int> r = make_pair( a.first / c, b.second / c );
    r = rec(*i, dst, vis, r);
    if( 0 < r.first && 0 < r.second )return r;
  }
  return make_pair( -1, -1 );
}

int main(void)
{
  char c;  
  while( cin >> c ){
    if( c == '.' )break;
    else if( c == '!' ){
      int a, b;
      string s, t;
      cin >> a >> s >> c >> b >> t;
      int tmp = gcd( max(a, b), min(a, b) );
      a /= tmp;
      b /= tmp;
      rate[ make_pair( s, t ) ] = make_pair( a, b );
      rate[ make_pair( t, s ) ] = make_pair( b, a );
      e[ s ].push_back( t );
      e[ t ].push_back( s );
    }
    else if( c == '?' ){
      string s, t;
      set<string> vis;
      cin >> s >> c >> t;
      pair<int, int> r = rec(s, t, vis, make_pair(1, 1));
      if( r.first < 0 || r.second < 0 ){
        cout << "? " << s << " = " << "? " << t << endl;
      }
      else{
        cout << r.first << " " << s << " = " << r.second << " " << t << endl;
      }
    }
  }
  return 0;
}

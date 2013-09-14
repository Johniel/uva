#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long int lli;

/*
set< string > dic;
map< string, string > miss;
*/

set< lli > dic;
map< lli, lli > miss;
map< lli, string > rev;

inline lli calc_hash( string s )
{
  lli h = 0;
  for(int i=0; i<s.size(); ++i){
    h *= 107;
    h += s[i] - 'a' + 1;
    h %= 1000000000000LL;
  }
  return h;
}

string solve(string s)
{ 
  string t;
  lli h = calc_hash(s);
  if( dic.count( s ) ){
    return s + " is correct";  
  }
  if( miss.find( s ) != miss.end() ){
    return s + " is a misspelling of " + miss[s];
  }
  t = s;
  sort( t.begin(), t.end() );
  if( miss.count( t ) ){
    return s + " is a misspelling of " + miss[t];
  }
  return s + " is unknown";
}

void make_dic(string s)
{
  string t, u;
  lli h, H;
  
  H = h = calc_hash( s );
  dic.insert( h );
  rev[h] = s;

  if( 1 < s.size() ){
    for(int i=0; i<s.size(); ++i){
      t = s;
      t.erase( t.begin() + i );
      h = calc_hash( t );
      if( miss.find( h ) == miss.end() ){
        miss[ h ] = H;      
        rev[ h ] = t;
      }
    }
  }
  u = "";
  for(int i=0; i<s.size(); ++i){
    for(char c='a'; c<='z'; ++c){
      t = u;
      t += c;
      t += s.substr( i );
      h = calc_hash( t );
      if( miss.find( h ) == miss.end() ){
        miss[h] = s;
        rev[h] = H;
      }
    }
    u += s[i];
  }
  for(char c='a'; c<='z'; ++c){
    t = s;
    t += c;
    h = calc_hash( t );
    if( miss.find( h ) == miss.end() ){
      miss[h] = s;
      rev[h] = H;
    }
  }

  for(int i=0; i<s.size(); ++i){
    t = s;
    for(char c='a'; c<='z'; ++c){
      t[i] = c;
      h = calc_hash( t );
      if( miss.find( h ) == miss.end() ){
        miss[h] = s;
        rev[h] = H;
      }
    }
  }
  t = s;
  sort( t.begin(), t.end() );
  h = calc_hash( t );
  if( miss.find( h ) == miss.end() ){
    miss[h] = s;
    rev[h] = H;
  }
  return ;
}

int main(void)
{
  int n, m;
  string s;
  while( cin >> n && n ){
    init();
    while(n--){
      cin >> s;
      make_dic( s );
    }
    cin >> m;
    while(m--){
      cin >> s;
      cout << solve( s ) << endl;
    }
  }
  return 0;
}

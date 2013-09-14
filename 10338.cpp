#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef unsigned long long int lli;

lli fact(lli n)
{
  if( n == 0 )return 1;
  for(lli i=2, m=n; i<m; ++i){
    n *= i;
  }
  return n;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    map<char, lli> t;
    getline( cin, s );
    for(int i=0; i<s.size(); ++i){
      ++t[ s[i] ];
    }
    lli r = fact( s.size() );
    lli same = 0;
    for(char c = 'a'; c <= 'z'; ++c){
      if( 1 < t[c] )r /= fact( t[c] );
    }
    for(char c = 'A'; c <= 'Z'; ++c){
      if( 1 < t[c] )r /= fact( t[c] );
    }
    cout << "Data set " << ++cnt << ": " << r << endl;
  }
  return 0;
}

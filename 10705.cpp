// uva 10705

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  int tc;
  cin >> tc;
  while( tc-- ){
    lli size, n, bit = 1;
    string s, r;
    cin >> size >> s >> n;
    for(int i=size-1; 0<=i; --i){      
      if( n & bit ){
        r += '1';
        n -= ( s[i] == 'p' ) ? bit : -bit;
      }
      else{
        r += '0'; 
      }
      bit <<= 1;
    }
    reverse( r.begin(), r.end() );
    cout << ( n ? "Impossible" : r ) << endl;
  }
  return 0;
}

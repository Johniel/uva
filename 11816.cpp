#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

typedef long long int lli;

lli pow10(int p)
{
  lli n = 1;
  while(p--)n *= 10;
  return n;
}

lli conv(string t)
{
  lli n = 0, cnt = 0;
  bool flg = false;
  for(int j=0; j<t.size(); ++j){
    if( t[j] == '.' )flg = true;
    if( isdigit( t[j] ) ){
      if( flg )++cnt;
      n = n * 10 + ( t[j] - '0' );
    }
  }
  return n * pow10(2 - cnt);
}

lli tax(lli n, lli t)
{
  lli tmp = n * t;
  if(tmp % 10000 < 5000)return tmp / 10000;
  else return tmp / 10000 + 1;
}

int main(void)
{
  int tc;
  cin >> tc;
  while( tc-- ){
    map<string, lli> a, b, c;
    string s, t;
    char d;
    int p, q;
    lli tmp[3], sum = 0;
    cin >> p >> q;
    while( p-- ){
      cin >> s;
      for(int i=0; i<3; ++i){
        cin >> t;
        tmp[i] = conv( t );
      }
      a[ s ] = tmp[0];
      b[ s ] = tmp[1];
      c[ s ] = tmp[2];
    }
    while( q-- ){
      cin >> s >> t;
      lli n = conv( t );
      lli x, y, z;
      x = tax( n, a[ s ] );
      y = tax( n, b[ s ] );
      z = tax( n, c[ s ] );
      sum += z - (x + y);

    }    
    if(0 <= sum)printf("%lld.%02lld\n", sum / 100, sum % 100);
    else{
      sum *= -1;
      printf("-%lld.%02lld\n", sum / 100, sum % 100);
    }
  }
  return 0;
  cout << conv("12.34") << endl;
  cout << conv("12.3") << endl;
  cout << conv("0.12") << endl;
  cout << conv("3.02") << endl;
  cout << conv("12") << endl;
  return 0;
}

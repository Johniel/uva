#include <iostream>
#include <algorithm>

using namespace std;

const int NUM = 3000;
const int N = (1 << 29);

inline
int rev(char c)
{
  if( isdigit(c) )return c - '0';
  else return c - 'A' + 10;
}

string add(string a, string b, int base)
{
  const string s = "0123456789ABCDEF";  
  string c;
  int size = a.size();
  int tmp = 0;
  for(int i=0; i<size; ++i){
    int n = rev( a[i] ) + rev( b[i] ) + tmp;
    tmp = n / base;    
    n %= base;
    c += s[ n ];
  }
  if( tmp )c += s[tmp];
  return c;
}

int solve(string s, int base)
{
  for(int i=0; i<100; ++i){
    string t = s;
    reverse( t.begin(), t.end() );
    if(s == t)return i;
    s = add(s, t, base);    
  }
  return -1;
}

int main(void)
{
  string s;
  while( cin >> s ){
    int mx = 0;
    for(int i=0; i<s.size(); ++i){
      mx = max(mx, rev(s[i]) + 1);
    }
    int r[16];
    fill(r, r + 16, -1);
    for(int i=mx; i<=15; ++i){
      r[i] = solve(s, i);
    }
    for(int i=15; 2<=i; --i){
      if(i-15)cout << ' ';
      if( r[i] < 0 )cout << '?';
      else cout << r[i];
    }
    cout << endl;
  }
  return 0;
}

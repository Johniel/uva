// 10104

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b)
{
  return b ? gcd(b, a % b) : a;
}

lli rec(lli a, lli b, lli &x, lli &y)
{
  lli c = a;
  x = 1;
  y = 0;
  if(b){
    c = rec(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return c;
}

// a x + b y = gcd(a, b)
pair<lli, lli> ex_gcd(lli a, lli b)
{
  lli x, y;
  rec(a, b, x, y);
  return make_pair(x, y);
}

int main(void)
{
  for(lli a, b; cin >> a >> b; ){
    pair<lli, lli> p;
    if(a < b){
      p = ex_gcd(a, b);
    }    
    else{
      p = ex_gcd(b, a);
      swap(p.first, p.second);
    }
    if(a == b){
      if(p.first > p.second){
	swap(p.first, p.second);
      }
    }
    cout << p.first << ' ' << p.second << ' ' 
	 << gcd(max(a, b), min(a, b)) << endl;
  }
  return 0;
}

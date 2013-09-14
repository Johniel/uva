#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int N = 200000 + 1;

int eulerPhi(int n)
{
  if(n == 0)return 0;
  int re = n;
  for(int m = 2; m * m <= n; ++m){
    if(n % m)continue;
    re -= re / m;
    while(n % m == 0)
      n /= m;    
  }
  return (n > 1)? re - re / n : re;
}

lli gcd(lli a, lli b)
{
  return b == 0 ? a : gcd(b, a%b);

  return (a%b)? gcd(b, a%b) : b;
}

int main(void)
{
  static lli sum[N];

  sum[0] = 0;
  sum[1] = 2;
  for(int i=2; i<N; ++i){
    sum[i] = sum[i - 1] + eulerPhi(i);
  }
  for(lli n; ; ){
    cin >> n;
    if(n == 0)break;
    if(n == 2){
      cout << "1/1" << endl;
      continue;
    }
    if(n != 1){
      //n--;
    }
    int r = 0, l = N-1, c;
    while(l > r + 1){
      c = (l + r) / 2;
      if(n < sum[c])l = c;
      else r = c;
    }    
    lli tmp = sum[r];
    //lli m = (n == 1)? 0 : 1;
    lli m = 1;
    if(tmp == n){
      tmp = sum[--r];
    }
    if(n == 1){
      cout << "0/1" << endl;
    }    
    else{
      ++r;      
      while(tmp != n){      
	//cout << n - tmp << ' ' << r << ' ' << m << endl;
	if(m && gcd(m, r) == 1){
	  ++tmp;
	}
	if(tmp == n)break;
	if(++m >= r){
	  ++r;
	  m = 1;
	  //m = 0;
	}
      }
      cout << m << '/' << r << endl;
    }
  }
  return 0;
}

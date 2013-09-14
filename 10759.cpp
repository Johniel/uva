#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int lli;

lli gcd(lli a, lli b)
{
  return b? gcd(b, a%b) : a;
}

void dp(int n, int m)
{
  const int T = 24+1, SUM = 150 * T;
  lli t[T][SUM];
  fill(&t[0][0], &t[T-1][SUM-1], 0);
  for(int i=1; i<=6; ++i){
    t[0][i] = 1;
  }
  lli a = 0, b = 6;
  for(int i=0; i<n-1; ++i){
    b *= 6;
    for(int j=0; j<SUM; ++j){
      if(t[i][j] == 0)continue;
      for(int k=1; k<=6; ++k){
	t[i+1][j+k] += t[i][j];
      }
    }
  }    
  for(int i=m; i<SUM; ++i){
    a += t[n-1][i];
  }
  if(a && b){
    if(a == b)cout << 1 << endl;
    else{
      lli c = gcd(b, a);
      cout << a / c << '/' << b / c << endl;
    }
  }
  else cout << 0 << endl;
  return ;
}

int main(void)
{
  for(int n, m; cin >> n >> m && (n || m); dp(n, m));
  return 0;
}

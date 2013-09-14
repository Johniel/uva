#include <iostream>
#include <algorithm>

using namespace std;

inline 
bool valid(int x, int p, int n)
{
  return x * p <= n && n < x * (p + 1);
}

int main(void)
{
  const int N = 10000 + 1;//n-p*x is
  bool prime[N];
  int tc, n;
  
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j)
      prime[i * j] = false;
  }
  
  int foo = 0;

  for(cin >> tc; tc--; ){
    cin >> n;    
    int tmp = -1, ans, test;
    for(int x=n-1; x>=0; --x){
      if(!prime[x])continue;
      for(int p = 1; p <= N; ++p){
	if(valid(x, p, n) && tmp < n - x * p){
	  tmp = n - x * p;
	  ans = x;
	  test = p;
	}
      }
    }      
    cout << ans << endl;
  }
  return 0;
}

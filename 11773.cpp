#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstdio>

#define REP(i, n) for(int i=0; i<n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

int main(void)
{
  const int P = 1000000;
  static bool prime[P];
  int size = 0, tc, cnt = 0;
  static lli p[P], n, tmp, a, b, m; 
  for(lli i=3; i<P; i+=2){
    prime[i] = true;
  }
  for(lli i=2; i*i<P; ++i){
    if(!prime[i])continue;
    for(lli j=i*i; j<P; j+=i){
      prime[j] = false;
    }
  }
  p[size++] = 2;
  for(lli i=3; i<P; i+=2){
    if(prime[i]){
      p[size++] = i;
    }
  } 

  scanf("%d", &tc);
  while(tc--){
    a = b = 0;
    scanf("%lld", &n);
    tmp = n;
    REP(i, size && p[i] <= n){
      if(n % p[i] == 0){
	m = 1;
	while(n % p[i] == 0){
	  n /= p[i];
	  m *= p[i];
	}
	if(m == tmp)break;
	if(a - b < tmp / p[i] - m){
	  a = tmp / p[i];
	  b = m;
	}
      }
      
    }
    printf("Case %d: ", ++cnt);
    if(a - b == 0)puts("Impossible");
    else printf("%lld %lld\n", a, b);
  }
  return 0;
}

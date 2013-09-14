#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long int lli;

const lli N = 10000000;

bool prime[N];
lli p[N], size = 0, fact[N];

inline
lli binary_search(lli n)
{
  lli r = 0, l = 2703663 + 1, c;
  while(l > r+1){
    c = (r + l) / 2;
    if(fact[c] <= n)r = c;
    else l = c;
  }
  return r;
}

int main(void)
{
  fill(fact, fact + N, 0);
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;

  for(lli i=2; i*i<N; ++i){
    for(lli j=2; i*j<N; ++j){
      prime[i*j] = false;
    }
  }

  for(lli i=0; i<N; ++i){
    if(prime[i])p[size++] = i;
  }

  fact[1] = 1;
  for(lli i=1; i<N; ++i){
    if(fact[i] == 0)continue;
    for(lli j=0; j<size; ++j){
      if(i * p[j] < N){
	fact[i * p[j]] = fact[i] + 1;
      }
      else break;
    }
  }

  /*
  for(int i=0; i<11; ++i){
    cout << i << ' ' << fact[i] << endl;
  }
  */

  --fact[1];
  for(int i=2; i<N; ++i){
    fact[i] += fact[i-1] - 1;
  }

  /*
  for(int i=0; i<11; ++i){
    cout << i << ' ' << fact[i] << endl;
  }
  */

  lli tc, n;
  for(scanf("%lld\n", &tc); tc--; ){
    scanf("%lld\n", &n);
    printf("%lld\n", binary_search(n)+1);
  }
  return 0;
}

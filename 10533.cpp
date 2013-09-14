#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000000;
const int M = 1000;
bool prime[N], rev[N];
int region[N];
int tc;

inline 
bool isDPrime(int n)
{
  return prime[n] && rev[n];
}

int main(void)
{
  fill(prime, prime + N, true);
  fill(region, region + N/M + 1, 0);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j){
      prime[i * j] = false;
    }
  }  
  int total = 0;
  for(int i=0; i<N; ++i){    
    if(!prime[i]){    
      region[i] = total;
      continue;
    }
    int sum = 0, n = i;
    while(10 <= n){
      sum += n % 10;
      n /= 10;
    }
    if(rev[i] = prime[sum + n]){
      ++total;
    }
    region[i] = total;
  }
  for(scanf("%d\n", &tc); tc--; ){
    int n, m, cnt = 0;
    scanf("%d %d\n", &n, &m);    
    printf("%d\n", region[m] - region[n] + isDPrime(n));
  }
  return 0;
}

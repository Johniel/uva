#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second

using namespace std;

typedef long long int lli;

const int P = 100000000 + 1;

bool prime[P];

inline
void msg(int a, int b, bool f)
{
  if(f)printf("%d is the sum of %d and %d.\n", a + b, a, b);
  else printf("%d is not the sum of two primes!\n", a + b);
  return ;
}

inline
void mark_prime(void)
{
  prime[2] = true;
  for(int i=3; i<P; i+=2){
    prime[i] = true;
  }
  for(int i=3; i*i<P; i+=2){
    if(!prime[i])continue;
    for(int j=i*i; j<P; j+=i){
      prime[j] = false;
    }
  }
  return ;
}

inline
void solve(int n)
{
  if(n % 2)msg(2, n-2, prime[n-2]);
  else{
    bool flg = false;
    for(int i=n/2+1; i<n; ++i){
      if(prime[i] && prime[n-i]){
        msg(n-i, i, flg = true);
        break;
      }
    }
    if(!flg)msg(n, 0, false);
  }
  return ;
}

int main(void)
{
  mark_prime();
  for(int n; scanf("%d", &n) != EOF; solve(n));
  return 0;
}

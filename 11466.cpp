#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int N = 10001000;
bool prime[N];

int main(void)
{
  prime[0] = prime[1] = true;  
  for(int i = 4; i < N; i +=2 ){
    prime[i] = true;
  }
  for(int i = 3; i * i < N; i += 2){
    if( prime[i] )continue;
    for(int j = i * i; j < N; j += 2 * i){
      prime[j] = true;
    }
  }
  static lli p[N], size = 0;
  p[size++] = 2;
  for(int i=3; i<N; i +=2 ){
    if( !prime[i] )p[size++] = i;
  }
  lli n; 
  while( scanf("%Ld", &n) && n ){
    int cnt = 0;
    lli mn = 1LL << 60, mx = -1;
    bool neg = n < 0;
    if( n < 0 )n *= -1;
    for(lli i=0; i<size; ++i){
      while( n % p[i] == 0 ){
        mx = max(mx, p[i]);
        mn = min(mn, p[i]);
        ++cnt;
        n /= p[i];
      }
    }
    if( n != 1 ){
      mx = max(mx, n);
      mn = min(mn, n);
      ++cnt;
    }
    if(cnt <= 1 || mx == mn)puts("-1");
    else printf("%Ld\n", mx);
  }
  return  0;
}

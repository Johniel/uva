#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int lli;

const lli P = 2000000ll;
bool prime[P];
lli p[150000 + 1];
int size;

int main(void)
{
  fill(prime, prime + P, false);
  prime[0] = prime[1] = true;
  for(lli i=2; i*i<P; ++i){
    for(lli j=2; i*j<P; ++j){
      prime[i * j] = true;
    }
  }

  for(lli i=0; i<P; ++i){
    if(!prime[i]){
      p[size++] = i;
    }
  }

  fill(prime, prime + P, false);
  for(int i=0; i < size && p[i] * p[i] < P; ++i){
    for(int j=0; j < size && p[i] * p[j] < P; ++j){
      prime[p[i] * p[j]] = true;
    }
  }

  
  /*
  for(int i=0; i<40; ++i){
    if(prime[i])cout << i << endl;
  }
  cout << count(prime, prime + 1048556, true) << endl;
  */

  for(lli n, m; scanf("%Ld", &n) != EOF; ){
    int cnt = 0;
    
    while(n--){
      scanf("%Ld", &m);
      cnt += prime[m];
    }
    printf("%d\n", cnt);
  }
  return 0;
}

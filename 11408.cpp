#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int N = 5000000 + 1;
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j){
      prime[i*j] = false;
    }
  }
  static lli p[N], size = 0;
  for(int i=0; i<N; ++i){
    if(prime[i])p[size++] = i;
  }
  static lli sum[N];
  fill(sum, sum + N, 0);
  for(int i=0; i<size; ++i){
    for(int j=p[i]; j<N; j+=p[i]){
      sum[j] += p[i];
    }
  }
  int cnt = 0;
  for(int i=2; i<N; ++i){
    sum[i] = cnt += prime[ sum[i] ];
  }

  lli n, m;
  while( cin >> n >> m && (n | m) ){
    cout << sum[m] - sum[n - 1] << endl;
  }
  return 0;
}

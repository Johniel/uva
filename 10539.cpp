#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int N = 1000000 + 100;
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
  static lli ap[100000], ap_size = 0;
  fill( ap, ap + 100000, -1);
  for(int i=0; i<size; ++i){
    lli n = p[i] * p[i];
    while(n < 1000000000000LL){
      ap[ ap_size++ ] = n;
      n *= p[i];
    }
  }
  sort( ap, ap + ap_size );
  int tc;
  cin >> tc;
  while(tc--){
    lli a, b;
    cin >> a >> b;
    lli *i = lower_bound( ap, ap + ap_size, a );
    lli *j = upper_bound( ap, ap + ap_size, b );
    cout << j - i << endl;
  }
  return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int lli;

const int M = 10000 + 1;
const int N = M * M + M + 41ll;
bool prime[N];
int sum[N];

inline int f(int n)
{
  return n * n + n + 41;
}

int main(void)
{
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=i*i; j<N; j+=i)
      prime[j] = false;
  }

  cout << "test" << endl;

  for(int i=0; i<N; ++i){
    sum[i] = prime[f(i)];
  }
  
  cout << "test" << endl;

  for(int i=1; i<N; ++i){
    sum[i] += sum[i - 1];
  }

  cout << "test" << endl;

  for(int a, b; cin >> a >> b; ){
    
    double p = sum[b] - sum[a];
    double q = b - a;

    printf("%.2lf\n", p / q * 100.0);
  }
  return 0;
}

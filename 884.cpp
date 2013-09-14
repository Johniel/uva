#include <iostream>

using namespace std;

int main(void)
{
  const int N = 1000000;
  bool prime[N];
  int p[N], cnt = 0, f[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i * i < N; ++i)
    for(int j=2; i * j < N; ++j)
      prime[i * j] = false;
  for(int i=0; i<N; ++i){
    if(prime[i])
      p[cnt++] = i;
  }    
  cout << "num of prime " << cnt << endl;
  fill(f, f + N, 0);
  for(int i=1; i<N; ++i){    
    int n = i;
    cout << i << endl;
    if(f[i])continue;
    for(int j=0; j<cnt; ++j){
      if(n % p[j] == 0){
	while(n % p[j] == 0){
	  n /= p[j];
	  ++f[i];
	}
      }
    }
    if(n != 1)++f[i];
    if(i * 2 <= N)f[i * 2] = f[i] + 1;
    if(i * 3 <= N)f[i * 3] = f[i] + 1;
    if(i * 4 <= N)f[i * 4] = f[i] + 2;
    if(i * 5 <= N)f[i * 5] = f[i] + 1;
    if(i * 6 <= N)f[i * 6] = f[i] + 2;
    if(i * 7 <= N)f[i * 7] = f[i] + 1;
    if(i * 8 <= N)f[i * 8] = f[i] + 3;
    if(i * 9 <= N)f[i * 9] = f[i] + 2;
    if(i * 10 <= N)f[i * 10] = f[i] + 2;
  }

  for(int i=1; i<N; ++i){
    f[i] += f[i-1];
  }

  int n;
  while(cin >> n){
    cout << f[n] << endl;
  }
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int P = 500000 + 1;
bool prime[P];
int p[P], size = 0;
int sopf[P];

int rec(int n, int depth)
{
  if(n == sopf[n])return depth;
  return rec(sopf[n], depth + 1);
}

int main(void)
{
  fill(prime, prime + P, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<P; ++i){
    for(int j=2; i*j<P; ++j){
      prime[i*j] = false;
    }
  }
  for(int i=0; i<P; ++i){
    if(prime[i])p[size++] = i;
  }
  fill(sopf, sopf + P, 0);
  for(int i=0; i<size; ++i){
    sopf[p[i]] = p[i];
  }  
  for(lli i=0; i<P/2; ++i){
    for(lli j=0; j<size; ++j){
      lli tmp = i * p[j];
      if(P <= tmp)break;
      sopf[tmp] = sopf[i] + p[j];
    }
  }
  sopf[0] = 0;

  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    int n, m;
    int mx = 0;
    cin >> n >> m;
    if(m < n)swap(n, m);
    for(int i=n; i<=m; ++i){
      mx = max(mx, rec(i, 0) + 1);
    }
    cout << "Case #" << ++cnt << ":" << endl << mx << endl;
  }  
  return 0;
}

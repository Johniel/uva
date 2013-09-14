#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

lli pow(lli n, lli p, lli mod)
{
  if(p == 0)return 1;
  if(p == 1)return n;
  lli m = pow(n, p/2, mod);
  m %= mod;
  m *= m;
  m %= mod;
  return p%2? m * n : m;
}

int main(void)
{ 
  //            1000000000
  const int P = 1000000;
  bool prime[P];
  int p[P], size = 0;
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
  lli n, m;
  while(cin >> m >> n && (n | m)){
    bool flg;
    if(m < P)flg = prime[m];
    else{
      int tmp = m;
      for(int i=0; i<size; ++i){
        while(m % p[i] == 0)m /= p[i];
      }
      flg = m != 1;
      m = tmp;
    }
    if(flg)cout << "no" << endl;
    else{
      int a = pow(n, m, m) % m;
      cout << (a == n? "yes" : "no") << endl;
    }
  }
  return 0;
}

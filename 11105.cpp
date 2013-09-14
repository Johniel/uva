#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

inline
int hn(int n)
{
  return 4 * n + 1;
}

const int P = 1000001 + 1;
bool prime[P];
int h[P], size = 0;
int r[P];
int sp[P];
int sum[P];

int main(void)
{
  fill(prime, prime + P, false);
  for(int i=0; ; ++i){
    int n = hn(i);
    if(P <= n)break;
    prime[n] = true;;
    h[size++] = n;
  }

  fill(r, r + P, true);  
  for(int i=1; i<size && h[i] * h[i] < P; ++i){
    if(!prime[h[i]])continue;
    for(int j=1; j<size && h[i] * h[j] < P; ++j){
      prime[h[i] * h[j]] = false;

      if(prime[h[j]])r[h[i] * h[j]] = true;
      else r[h[i] * h[j]] = false;
    }
  }  

  int s = 0;  
  for(int i=1; i<P; ++i){
    if(r[h[i]] && !prime[h[i]]){
      sp[s++] = h[i];
      ++sum[h[i]];
    }
  }

  for(int i=2; i<P; ++i){
    sum[i] += sum[i-1];
  }

  for(int n; cin >> n && n; ){
    cout << n << ' ' << sum[n] << endl;
  }
  return 0;
}

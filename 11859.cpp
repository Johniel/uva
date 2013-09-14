#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int P = 10000 + 1;

int solve(int p[], int size, int n)
{
  int sum = 0;
  for(int i=0; i<size && 1 < n; ++i){
    while(n % p[i] == 0){
      ++sum;
      n /= p[i];
    }
  }
  if(n != 1)++sum;
  return sum;
}

int main(void)
{
  bool prime[P];
  int p[P], size = 0;
  fill(prime, prime + P, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<P; ++i){
    for(int j=2; i*j<P; ++j){
      prime[i * j] = false;
    }
  }
  for(int i=0; i<P; ++i){
    if(prime[i])p[size++] = i; 
  }
  int tc, cnt = 0;
  int m[50][50], nim[50];
  cin >> tc;
  while(tc--){
    int h, w, exor = 0, r = 0;
    cin >> h >> w;
    for(int i=0; i<h; ++i){
      nim[i] = 0;
      for(int j=0; j<w; ++j){
	cin >> m[i][j];
	nim[i] += solve(p, size, m[i][j]);
      }
      cout << nim[i] << endl;
      exor ^= nim[i];
    }
    while(exor){
      if(exor & 1)++r;
      exor = exor >> 1;
    }
    cout << "Case #" << ++cnt << ": " << (r % 2 ? "YES" : "NO") << endl;
  }
  return 0;
}

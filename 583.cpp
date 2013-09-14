#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;  

typedef long long int lli;

const lli N = 47000;

int main(void)
{
  bool prime[N];
  int p[N];
  int size = 0;
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; i*j<N; ++j){
      prime[i * j] = false;
    }
  }
  for(int i=0; i<N; ++i){
    if(prime[i])p[size++] = i;
  }

  for(int n; cin >> n && n; ){
    int cnt = 0;
    cout << n << " =";
    if(n < 0){
      ++cnt;
      cout << " -1";
      n *= -1;
    }    
    for(int i=0; i<size; ++i){
      while(n % p[i] == 0){
	if(cnt)cout << " x ";
	else cout << " ";
	cout << p[i];
	n /= p[i];
	++cnt;
      }
    }
    if(n != 1){
      if(cnt)cout << " x ";
      else cout << " ";
      cout << n ;
    }
    cout << endl;
  }

  return 0;
}

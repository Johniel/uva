#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int N = 1003000;   
bool prime[N];
lli p[N], size = 0;

int main(void)
{
  
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  
  for(int i=2; i * i < N; ++i){
    for(int j=2; i * j < N; ++j){
      prime[i * j] = false;
    }
  }

  for(int i=0; i<N; ++i){
    if(prime[i])p[size++] = i;
  }
  
  //cout << p[size-1] << endl;cout << 1000000 << endl;

  for(lli n; ; ){
    cin >> n;
    if(n < 0)break;
    for(int i=0; i<size; ++i){
      if(n % p[i] == 0){
	while(n % p[i] == 0){
	  n/=p[i];
	  cout << "    " << p[i] << endl;
	}	
      }
    }
    if(n != 1)cout << "    " << n << endl;
    cout << endl;
  }
  return 0;
}

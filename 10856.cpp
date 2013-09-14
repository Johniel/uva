#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N = 10000001 + 1;

static bool prime[N];
static int p[N], size = 0;
static int pf[N];

int main(void)
{
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
  for(int i=0; i<size; ++i){
    pf[p[i]] = 1;
  }
  for(int i=0; i<N; ++i){
    for(int j=0; j<size; ++j){
      if(i * j < N){
        pf[i * j] = pf[i] + 1;
      }
    }
  }
  map<int, int> ans;
  int sum = 0;
  for(int i=2; i<N; ++i){
    sum += pf[i];
    ans[i] = sum;
  }   
  for(int n, tc = 0; cin >> n && n < 0; ){
    cout << "Case " << ++tc << ": " << flush;
    if( ans.find( n ) != ans.end() ){
      cout << ans[ n ] << "!" << endl;
    }
    else cout << "Not possible." << endl;
  }
  return 0;
}

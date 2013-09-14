#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main(void)
{
  const int N = 1000000;
  bool prime[N];
  int p[N], size = 0;

  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; j*i<N; ++j){
      prime[i*j] = false;
    }
  }

  for(int i=0; i<N; ++i){
    if(prime[i])p[size++] = i;
  }

  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    pair<int, int> result = make_pair(-1, -1);
    for(int i=0; i<size && n>p[i]; ++i){
      if(prime[n - p[i]]){
	result = make_pair(n - p[i], p[i]);
	break;
      }
    }
    cout << n << ":" << endl;
    if(result.first == -1){
      cout << "NO WAY!" << endl;
    }
    else cout << min(result.first, result.second) << '+' 
	      << max(result.first, result.second)<< endl;
  }
  return 0;
}

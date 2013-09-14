#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
  const int N = 1000000 + 1;
  bool prime[N];
  int p[N], size = 0;
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
  int tc;
  cin >> tc;
  while(tc--){
    map<int, int> cnt;
    int l, u;
    cin >> l >> u;
    for(int i=0; i<size; ++i){
      if(l <= p[i]){
        for(++i; i<size; ++i){
          if(u < p[i])break;
          //cout << p[i] << " : " << p[i-1] << endl;
          ++cnt[ p[i] - p[i-1] ];
        }
      }
    }
    int mx = -1;
    int v;
    map<int, int>::iterator itr;
    for(itr = cnt.begin(); itr != cnt.end(); ++itr){
      if(mx < itr->second){
        mx = itr->second;
        v = itr->first;
      }
    }
    int cr = 0;
    for(itr = cnt.begin(); itr != cnt.end(); ++itr){
      if(itr->second == mx)++cr;
    }
    if(mx == -1 || cr != 1)cout << "No jumping champion" << endl;
    else cout << "The jumping champion is " << v << endl;    
  }
  return 0;
}

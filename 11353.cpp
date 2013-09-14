#include <iostream>
#include <algorithm>

using namespace std;

const int P = 2000000 + 1;

bool prime[P];
int p[P], size = 0;
int cnt[P];
pair<int, int> q[P];

int main(void)
{
  prime[0] = prime[1] = false;
  for(int i=2; i<P; ++i){
    prime[i] = i;
  }
  for(int i=2; i*i<P; ++i){
    if(prime[i]){
      for(int j=i*i; j<P; j+=i){
        prime[j] = 0;
      }
    }
  }

  for(int i = 0; i < P; ++i){
    if(prime[i])p[size++] = i;
  }

  for(int i=0; i<P; ++i){
    if(prime[i])cnt[i] = 1;
    else{
      cnt[i] = 0;
      for(int j=0; j<size; ++j){
	if(i % p[j] == 0){
	  int n = i / p[j];
	  cnt[i] = cnt[n] + 1;
	  break;
	}
      }
    }    
  }  
  for(int i=0; i<P; ++i){
    q[i] = make_pair(cnt[i], i);
  }
  q[0] = make_pair(0, 0);
  sort(q, q + P);
  for(int n, tc = 0; cin >> n && n; ){
    cout << "Case " << ++tc << ": " << q[n].second << endl;
  }
  return 0;
}

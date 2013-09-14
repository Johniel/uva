#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct State{
  int n, cnt;
  State(int _n, int _c) : n(_n), cnt(_c) {}
};

int main(void)
{
  static const int N = 1000;
  vector<int> p;
  int tc = 0;
  bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for(int i=2; i*i<N; ++i){
    for(int j=2; j*i<N; ++j)
      prime[i*j] = false;
  }
  for(int i=0; i<N; ++i)
    if(prime[i])p.push_back(i);
  while(true){
    int a, b;
    cin >> a >> b;
    if(a == 0 && b == 0)break;
    queue<State> Q;
    set<int> S;
    int result = -1;
    for(Q.push(State(a, 0)), S.insert(a); !Q.empty(); Q.pop()){
      State n = Q.front();
      if(n.n == b){
	result = n.cnt;
	break;
      }
      int tmp = n.n;
      vector<int> pf;
      while(tmp != 1){
	for(int i=0; i<p.size(); ++i){
	  if(tmp%p[i] == 0){
	    pf.push_back(p[i]);
	    while(tmp%p[i] == 0)
	      tmp /= p[i];	      
	  }
	}	
      }
      for(int i=0; i<pf.size(); ++i){
	if(n.n == pf[i])continue;
	int tmp = n.n + pf[i];	
	if(S.count(tmp))continue;
	if(tmp <= b){
	  //cout << n.n << " + " << pf[i] << " = " << tmp << endl;
	  Q.push(State(tmp, n.cnt + 1));
	  S.insert(tmp);
	}
      }
    }
    cout << "Case " << ++tc << ": " << result << endl;
  }
  return 0;
}

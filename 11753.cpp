#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int L = 10000, INF = 30;

struct State{
  int r, l, cnt;
  State(int _r, int _l, int c) 
    : r(_r), l(_l), cnt(c) {}
};
/*
int rec(int r, int l, int num[], int n, int depth, int k, bool &succes)
{
  if(r >= l){
    success = true;
    return depth;
  }
  if(num[r] == num[l] && r+1 < n && 0 < l){
    int re = rec(r+1, l-1, n, depth, k, success);
    if(succes)return re;
  }
  else{
    if(r+1 < n){
      if(succes)return re;
    }
    if(0 < l){
      if(succes)return re;
    }
  }
  return 1 << 20;
}
*/
int main(void)
{
  const int L = 10000;
  int tc, num[L], cnt = 0;
  for(cin >> tc; tc--; ){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; ++i){
      cin >> num[i];
    }

    int re = 1 << 20, test = 0;
    bool succes = true;
    //re = rec(0, n-1, num, n, 0, k, succes);

    queue<State> Q;
    for(Q.push(State(0, n-1, 0)); !Q.empty(); Q.pop()){
      ++test;
      State s = Q.front();
      int r = s.r, l = s.l;
      if(r == l || r > l){
	re = s.cnt;
	break;
      }
      if(k < s.cnt){
	continue;
      }
      if(num[r] == num[l] && r+1 < n && 0 < l){
	Q.push(State(r+1, l-1, s.cnt));
      }
      else{
	if(r+1 < n){
	  Q.push(State(r+1, l, s.cnt+1));
	}
	if(0 < l){
	  Q.push(State(r, l-1, s.cnt+1));
	}
      }
    }
    //cout << re << ' ' << test << endl;

    cout << "Case " << ++cnt << ": " ;
    if(re == 0)cout << "Too easy" << endl;
    else if(re <= k)cout << re << endl;
    else cout << "Too difficult" << endl;
  }
  return 0;
}

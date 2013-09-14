#include <iostream>

using namespace std;

const int N = 10000 + 1;

int main(void)
{
  int t[N];
  for(int n, m, l; cin >> n >> m >> l; ){
    fill(t, t + N, 0);
    t[n] = t[m] = 1;
    int mx = -1, idx;
    for(int i=0; i<=l; ++i){
      if(mx <= t[i]){
	mx = t[i];
	idx = i;
      }
      if(t[i] == 0)continue;
      if(i + n <= l)
	t[i + n] = max(t[i] + 1, t[i + n]);
      if(i + m <= l)
	t[i + m] = max(t[i] + 1, t[i + m]);
    }
    if(t[l])cout << t[l] << endl;
    else if(mx == 0)cout << "0 " << l << endl;
    else{
      for(int i=l; i--; ){
	if(t[i]){
	  cout << t[i] << ' ' << l - i << endl;
	  break;
	}
      }
    }
  }
  return 0;
}

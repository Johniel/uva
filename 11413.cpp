#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  for(int n, m; cin >> n >> m; ){
    lli v[n], r = -1, l = 0;
    for(int i=0; i<n; ++i){
      cin >> v[i];
      l += v[i];
      r = max(r, v[i]);
    }
    ++l; --r;         
    lli result, ans = 2000000000000ll;
    while(l > r+1){
      lli c = (r + l) / 2, cnt = 1, sum = 0;
      result = -1;
      for(lli i=0; i<n; ++i){
	if(sum + v[i] > c){
	  sum = 0;
	  ++cnt;
	}
	sum += v[i];	
	result = max(result, sum);
	if(n - i ==  m - cnt){
	  for(int j=i+1; j<n; ++j){
	    result = max(result, v[j]);
	  }
	  cnt = m;
	  break;
	}
      }
      if(cnt == m)ans = min(result, ans);
      if(cnt > m)r = c;
      else l = c;
    }
    cout << (n==1? v[0] : ans) << endl;
  }
  return 0;
}

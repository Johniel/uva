#include <iostream>
#include <algorithm>

using namespace std;

inline
int count_bit(int n)
{
  //cout << "count_bit : " << n << endl;
  int cnt = 0;
  while(n){
    if(n & 1)++cnt;
    n >>= 1;
  }
  return cnt;
}

int dp(int n)
{
  const int T = 1 << 13;
  static bool t[T];
  fill(t, t + T, false);
  int mn = (1 << 25);
  t[n] = true;
  for(int k=12; k--; ){
    for(int i=T-1; i; --i){
      if(!t[i])continue;
      mn = min(mn, count_bit(i));
      for(int j=1; j<11; ++j){      
	if(i & (1 << j)){	
	  int r = i & (1 << (j + 1));
	  int l = i & (1 << (j - 1));
	  if((r && !l) || (!r && l)){
	    int m = i;
	    m ^= (1 << j);
	    m ^= 1 << (j + 1);
	    m ^= 1 << (j - 1);
	    t[m] = true;
	    //cout << i << " ==>> " << m << endl;
	  }
	}
      }
    }
  }
  return mn;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    string s;
    int n = 0;
    cin >> s;
    for(int i=0; i<s.size(); ++i){
      if(s[i] == 'o')n += 1 << i;
    }
    cout << dp(n) << endl;
  }
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  char c;
  int tc, h, m, n;
  for(cin >> tc; tc--; ){
    cin >> h >> c >> n;
    n = (n + h * 60 + 1) % (24 * 60) ;
    for(; ; n = (n + 1) % (24 * 60)){
      h = n / 60;
      m = n % 60;
      string s, t;
      s += '0' + h / 10;
      s += '0' + h % 10;
      s += '0' + m / 10;
      s += '0' + m % 10;            
      for(int i=0; i<s.size(); ++i){
	if(s[i] == '0'){
	  s.erase(s.begin() + i);
	  --i;
	}
	else break;
      }
      t = s;
      reverse(t.begin(), t.end());
      if(s == t)break;
    }
    printf("%02d:%02d\n", n/60, n%60);\
  }
  return 0;
}

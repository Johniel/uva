#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  while(true){
    int n, d = -1, r = -1, ans = 1 << 20;    
    cin >> n;
    if(n == 0)break;
    for(int i=0; i<n; ++i){
      char c;
      cin >> c;
      if(c == 'D'){	
	d = i;
	if(r == -1)continue;
	ans = min(ans, d - r);
      }
      else if(c == 'R'){
	r = i;
	if(d == -1)continue;
	ans = min(ans, r - d);
      }
      else if(c == 'Z'){
	ans = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

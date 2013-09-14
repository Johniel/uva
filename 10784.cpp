#include <iostream>

using namespace std;

typedef long long int lli;

int main(void)
{
  int tc = 0;
  for(lli n; ; ){
    cin >> n;
    if(n == 0)break;
    lli c, r = 0, l = 44721362 + 1;
    n *= 2;
    while(r+1 < l){
      c = (r + l) / 2;
      lli m = c * (c - 3);
      //cout << r << ' ' << l << ' ' << m << ' ' << n << endl;
      if(n <= m)l = c;
      else r = c;
    }
    cout << "Case " << ++tc << ": " << l << endl;
  }
  return 0;
}

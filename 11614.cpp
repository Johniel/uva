#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

typedef unsigned long long int lli;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    lli n, l = 0, r = 1000000000000000000ll, c;
    cin >> n;
    while(true){
      c = (l + r) / 2;
      if(c == l || c == r)break;
      lli tmp = (c % 2)? (c + 1) / 2 * c : c / 2 * (c + 1);
      if(n == tmp){
	l = c;
	break;
      }
      else if(tmp < n)l = c;
      else r = c;
    }
    cout << l << endl;
  }
  return 0;
}

#include <iostream>

using namespace std;

typedef long long int lli;


int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    lli x, k;
    cin >> x >> k;
    if(x % k == 0){
      cout << 0 << ' ' << k << endl;
    }
    else{
      cout << -x << ' ' << x << endl;
    }
  }
  return 0;
}

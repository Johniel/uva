#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int lli;

int main(void)
{  
  for(lli n; cin >> n && n; ){
    lli m = sqrt(n);
    cout << (m * m == n ? "yes" : "no") << endl;
  }
  return 0;
}

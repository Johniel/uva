#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

inline lli gc(lli n){ return n ^ (n >> 1); }

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    lli n, m;
    cin >> n >> m;
    cout << gc(m) << endl;
  }
  return 0;
}

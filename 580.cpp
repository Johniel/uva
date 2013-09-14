#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int T = 40 + 1;
  lli t[T];
  fill(t, t + T, 0);
  t[1] = (1L << 1);
  t[2] = (1L << 2);
  t[3] = (1L << 3) - 1;
  for(int i=4; i<T; ++i){
    t[i] = t[i-1] + t[i-2] + t[i-3]; 
  }
  for(int n; cin >> n && n; ){
    cout << (1L << n) - t[n] << endl;
  }

  return 0;
}

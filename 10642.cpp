#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli sigma(lli n)
{
  return n % 2 ? (n + 1) / 2 * n : n / 2 * (n + 1);
}

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    lli px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    lli a = sigma(px + py);
    lli b = sigma(qx + qy);
    cout << "Case " << ++cnt << ": " << b - a - px + qx << endl;
  }
  return 0;
}

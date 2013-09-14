#include <iostream>

using namespace std;

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    int n, k, p;
    cin >> n >> k >> p;
    cout << "Case " << ++cnt << ": ";
    cout << (k + p - 1) % n + 1 << endl;
   }
  return 0;
}

#include <iostream>

using namespace std;

typedef long long int lli;

int main(void)
{
  for(lli n; cin >> n; ){
    int cnt = 1;
    cout << "n = " << n << endl;
    for(lli ones = 1; ones % n; ++cnt, ones = ones * 10 + 1){
      cout << cnt << ' ' << ones << endl;
    }
    cout << cnt << endl;
  }
  return 0;
}

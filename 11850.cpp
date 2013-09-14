#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int charge[1422 + 2 + 1];
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    for(int i=0; i<n; ++i){
      cin >> charge[i];
    }
    sort(charge, charge + n);
    bool flg = true;
    for(int i=0; i<n-1 && flg; ++i){
      flg = flg && (charge[i + 1] - charge[i] <= 200);
    }
    flg = flg && (charge[0] <= 200);
    flg = flg && ((1422 - charge[n-1]) * 2 <= 200);
    cout << (flg ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
  return 0;
}

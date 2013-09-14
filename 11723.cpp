#include <iostream>

using namespace std;

int main(void)
{
  int tc = 0;
  while(true){
    int r, n;
    cin >> r >> n;
    if(r == 0 && n == 0)break;
    cout << "Case " << ++tc << ": ";    
    int m = r / n - 1;
    if(r % n)++m;
    if(r <= n * 27)cout << m << endl;
    else cout << "impossible" << endl;
  }
  return 0;
}

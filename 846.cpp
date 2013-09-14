#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n, m, diff, cnt = 0;
    int no = 1, flg = 0;;
    cin >> n >> m;
    diff = m - n;
    while(0 < diff){
      diff -= no;
      ++cnt;
      if(flg)++no;
      flg ^= 1;
    }
    cout << cnt << endl;
  }
  return 0;
}


#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
  const int INF = 1 << 20;
  for(int m, b, h, w; cin >> m >> b >> h >> w; ){
    int sum = INF;
    for(int i=0, cost; i<h; ++i){
      cin >> cost;
      for(int j=0, cap; j<w; ++j){
	cin >> cap;
	if(m <= cap)
	  sum = min(sum, cost * m);
      }
    }
    if(sum != INF&& sum <= b){
      cout << sum << endl;
    }
    else cout << "stay home" << endl;
  }
  return 0;
}

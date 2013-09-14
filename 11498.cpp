#include <iostream>
#include <utility>

using namespace std;

int main(void)
{
  for(int n; cin >> n; ){
    if(n == 0)break;
    pair<int, int> base;
    cin >> base.first >> base.second;
    for(; n--; ){
      int h, w;
      cin >> h >> w;
      //cin >> w >> h;
      h -= base.first;
      w -= base.second;
      swap(h, w);
      if(h == 0 || w == 0){
	cout << "divisa" << endl;
	continue;
      }
      cout << ((h>0)? 'N' : 'S');
      cout << ((w>0)? 'E' : 'O');
      cout << endl;
    }
    
  }
return 0;
}

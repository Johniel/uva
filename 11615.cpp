#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int h, a, b;
    cin >> h >> a >> b;
    if(a == b){
      cout << 0 << endl;
      continue;
    }
    int whole = (1 << h) - 1;
    int s = 0;
    for(int i=a; i; i/=2)++s;
    int t = 0;
    for(int i=b; i; i/=2)++t;
    int mn = min(h - s, h - t);
    if(mn == 0)cout << whole << endl;
    else{
      ++mn;
      int bit = (1 << mn) - 1;
      //cout << "mn : " << mn << endl;
      //cout << "bit : " << bit << endl;
      cout << whole - bit + 1 << endl;
    }
  }
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  while(n--){
    int a, b;
    cin >> a >> b;
    int x = (a+b)/2, y = (a-b)/2;
    if( x<0 || y<0 || (a+b)%2 == 1 ||(a-b)%2==1 ){
      cout << "impossible" << endl;
      //break;
    }
    else{
      cout << max(x,y) << ' ' << min(x,y) << endl;
    }
  }
  return 0;
}
/*
x+y=40
x-y=20

2x = 60
2y = 20

x=30
y=10
*/

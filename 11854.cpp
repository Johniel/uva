#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  while(true){
    long long int a, b, c;
    cin >> a >> b >> c;
    if(a + b + c == 0)break;
    a *= a;
    b *= b;
    c *= c;
    if(a + b == c || 
       a + c == b || 
       b + c == a){
      cout << "right" << endl;
    }
    else cout << "wrong" << endl;
  }
  return 0;
}

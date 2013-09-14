#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int conv(int n, int base)
{
  int sum = 0, tmp = 1;
  while(n){
    sum += n % 10 * tmp;
    n /= 10;
    tmp *= base;
  }
  return sum;
}

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;

    int s = -1, tmp = n;
    while(tmp){
      s = max(s, tmp % 10);
      tmp /= 10;
    }

    for(int b=s+1; ; ++b){
      /*
      double m = conv(n, b);
      double s = sqrt(m);
      if(fabs(m - s * s) < 1e-7){
	cout << b << endl;
	break;
      }
      */
      int m = conv(n, b);
      int s = sqrt(m);
      if(m == s * s){
	cout << b << endl;
	break;
      }
    }
  }
  return 0;
}

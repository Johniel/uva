#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = 2 * acos(0);

int main(void)
{
  int n, tc = 0;
  double a;  
  while(cin >> n >> a){
    if(n < 3)break;
    double r = 2 * a / (n * sin(2 * PI / n));
    double s = r * PI - a;   

    r = sqrt(r);

    double h = r * cos(2 * PI / n / 2);

    double o = a - h * h * PI;

    printf("Case %d: %.5lf %.5lf\n", ++tc, s, o);
  }
  return 0;
}

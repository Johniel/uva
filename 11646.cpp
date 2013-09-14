#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int tc = 0;
  char c;
  double l, w;
  while(cin >> l >> c >> w){
    double r = sqrt((l / 2) * (l / 2) + (w / 2) * (w / 2));
    double x = 200.0 / (2 * r * acos(l / (2 * r)) + l);
    printf("Case %d: %.10lf %.10lf\n",++tc,  l * x, w * x);
  }
  return 0;
}

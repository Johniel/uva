//uva 10678
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double pi = 2 * acos(0);

double areaOfEllipse(double a, double b)
{
  return a * b * pi;
}

int main(void)
{
  int tc;
  double n, m;
  for(cin >> tc; tc--; ){
    cin >> n >> m;
    double a = m / 2;
    double b = sqrt((m/2) * (m/2) - (n/2) * (n/2));
    printf("%.3lf\n", areaOfEllipse(a, b));
  }
  return 0;
}
